/*
 *   File name: IIMainWindow.h
 *   Summary:	QDirStat main window
 *   License:	GPL V2 - See file LICENSE for details.
 *
 *   Author:	mh_68 <mh_68@gmail.com>
 */


#ifndef IMainWindow_h
#define IMainWindow_h

#include <QMainWindow>
#include <QString>

//#include <QElapsedTimer>
//#include <QTimer>
//#include <QPointer>

//#include "ui_main-window.h"
//#include "FileTypeStatsWindow.h"

//class QCloseEvent;
//class QSortFilterProxyModel;
//class QSignalMapper;
//class TreeLayout;

#if 0
namespace QDirStat
{
    class CleanupCollection;
    class ConfigDialog;
    class DirTreeModel;
    class FileInfo;
    class MimeCategorizer;
    class SelectionModel;
}

using QDirStat::FileInfo;
using QDirStat::FileTypeStatsWindow;

#endif

class IMainWindow: public QMainWindow
{
   // Q_OBJECT

public:

    IMainWindow();
    virtual ~IMainWindow() {}

public:

    /**
     * Open an URL (start reading that directory).
     **/
    virtual void openUrl( const QString & url ) =0 ;

    /**
     * Open a directory selection dialog and open the selected URL.
     **/
    virtual void askOpenUrl() =0 ;

    virtual void readCache( const QString & cacheFileName ) =0 ;

   virtual void setSlowUpdate() =0 ;




}; // class IMainWindow



#endif // IMainWindow_H
