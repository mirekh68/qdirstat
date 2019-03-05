/*
 *   File name: SysUtil.cpp
 *   Summary:	System utility functions for QDirStat
 *   License:	GPL V2 - See file LICENSE for details.
 *
 *   Author:	Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */


#include <unistd.h>	// access(), getuid(), geteduid()
#include <pwd.h>        // getpwuid()

#include "SysUtil.h"
#include "QDSProcess.h"
#include "Logger.h"
#include "Exception.h"

#define COMMAND_TIMEOUT_SEC	5

using namespace QDirStat;


bool SysUtil::tryRunCommand( const QString & commandLine,
			     const QRegExp & expectedResult,
			     bool	     logCommand,
			     bool	     logOutput	)
{
    int exitCode = -1;
    QString output = runCommand( commandLine, &exitCode, logCommand, logOutput );

    if ( exitCode != 0 )
    {
	// logDebug() << "Exit code: " << exitCode << " command line: \"" << commandLine << "\"" << endl;
	return false;
    }

    bool expected = expectedResult.exactMatch( output );
    // logDebug() << "Expected: " << expected << endl;

    return expected;
}


QString SysUtil::runCommand( const QString & commandLine,
			     int *	     exitCode_ret,
			     bool	     logCommand,
			     bool	     logOutput	)
{
    if ( exitCode_ret )
	*exitCode_ret = -1;

    QStringList args = commandLine.split( QRegExp( "\\s+" ) );

    if ( args.size() < 1 )
    {
	logError() << "Bad command line: \"" << commandLine << "\"" << endl;
	return "ERROR: Bad command line";
    }

    QString command = args.takeFirst();

    return runCommand( command, args, exitCode_ret, logCommand, logOutput );
}


QString SysUtil::runCommand( const QString &	 command,
			     const QStringList & args,
			     int *		 exitCode_ret,
			     bool		 logCommand,
			     bool		 logOutput  )
{
    if ( exitCode_ret )
	*exitCode_ret = -1;

    if ( ! haveCommand( command ) )
    {
	logInfo() << "Command not found: " << command << endl;
	return "ERROR: Command not found";
    }

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert( "LANG", "C" ); // Prevent output in translated languages

    Process process;
    process.setProgram( command );
    process.setArguments( args );
    process.setProcessEnvironment( env );
    process.setProcessChannelMode( QProcess::MergedChannels ); // combine stdout and stderr

    if ( logCommand )
	logDebug() << command << " " << args.join( " " ) << endl;

    process.start();
    bool success = process.waitForFinished( COMMAND_TIMEOUT_SEC * 1000 );
    QString output = QString::fromUtf8( process.readAll() );

    if ( success )
    {
	if ( process.exitStatus() == QProcess::NormalExit )
	{
	    if ( exitCode_ret )
		*exitCode_ret = process.exitCode();
	}
	else
	{
	    logError() << "Command crashed: \"" << command << "\" args: " << args << endl;
	    output = "ERROR: Command crashed\n\n" + output;
	}
    }
    else
    {
	logError() << "Timeout or crash: \"" << command << "\" args: " << args << endl;
	output = "ERROR: Timeout or crash\n\n" + output;
    }

    if ( logOutput )
	logDebug() << "Output: \n" << output << endl;

    return output;
}


void SysUtil::openInBrowser( const QString & url )
{
    logDebug() << "Opening URL " << url << endl;

    Process::startDetached( "/usr/bin/xdg-open", QStringList() << url );
}


bool SysUtil::haveCommand( const QString & command )
{
    return access( command.toUtf8(), X_OK ) == 0;
}


bool SysUtil::runningAsRoot()
{
    return geteuid() == 0;
}


bool SysUtil::runningWithSudo()
{
    return ! qgetenv( "SUDO_USER" ).isEmpty();
}


bool SysUtil::runningAsTrueRoot()
{
    return runningAsRoot() && ! runningWithSudo();
}


QString SysUtil::homeDir( uid_t uid )
{
    struct passwd * pw = getpwuid( uid );

    return pw ? QString::fromUtf8( pw->pw_dir ) : QString();
}
