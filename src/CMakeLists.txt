# qmake .pro file for qdirstat/src
#
# Go to the project toplevel dir and build all Makefiles:
#
#     qmake
#
# Then build with
#
#     make
#

#see: https://stackoverflow.com/questions/43763416/how-to-convert-qmake-to-cmake

#find_package(Qt5Core REQUIRED)
#find_package(Qt5Gui REQUIRED)
#find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

#target_link_libraries(my_lib PUBLIC Qt::Widgets)


#CONFIG		+= debug
#DEPENDPATH	+= .
#MOC_DIR		 = .moc
#OBJECTS_DIR	 = .obj
#LIBS		+= -lz

#major_is_less_5 = $$find(QT_MAJOR_VERSION, [234])
#!isEmpty(major_is_less_5):DEFINES += 'Q_DECL_OVERRIDE=""'
#isEmpty(INSTALL_PREFIX):INSTALL_PREFIX = /usr

#TARGET		 = qdirstat
#TARGET.files	 = qdirstat
#TARGET.path	 = $$INSTALL_PREFIX/bin
#INSTALLS	+= TARGET desktop icons

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set( SOURCES  
		#main.cpp			
		#QDirStatApp.cpp             
	    ActionManager.cpp		
	    AdaptiveTimer.cpp		
	    Attic.cpp			
	    BreadcrumbNavigator.cpp	
	    BucketsTableModel.cpp	
	    BusyPopup.cpp		
	    Cleanup.cpp			
	    CleanupCollection.cpp	
	    CleanupConfigPage.cpp	
	    ConfigDialog.cpp		
	    DataColumns.cpp		
	    DebugHelpers.cpp		
	    DelayedRebuilder.cpp	
	    DirInfo.cpp			
	    DirReadJob.cpp		
	    DirSaver.cpp		
	    DirTree.cpp			
	    DirTreeCache.cpp		
	    DirTreeModel.cpp		
	    DirTreePatternFilter.cpp	
	    DirTreePkgFilter.cpp	
	    DirTreeView.cpp		
	    DiscoverActions.cpp		
	    DotEntry.cpp		
	    DpkgPkgManager.cpp		
	    Exception.cpp		
	    ExcludeRules.cpp		
	    ExcludeRulesConfigPage.cpp	
	    ExistingDirCompleter.cpp	
	    ExistingDirValidator.cpp	
	    FileAgeStats.cpp		
	    FileAgeStatsWindow.cpp	
	    FileDetailsView.cpp		
	    FileInfo.cpp		
	    FileInfoIterator.cpp	
	    FileInfoSet.cpp		
	    FileInfoSorter.cpp		
	    FileMTimeStats.cpp		
	    FileSizeLabel.cpp		
	    FileSizeStats.cpp		
	    FileSizeStatsWindow.cpp	
	    FileSystemsWindow.cpp	
	    FileTypeStats.cpp		
	    FileTypeStatsWindow.cpp	
	    FormatUtil.cpp		
	    GeneralConfigPage.cpp	
	    HeaderTweaker.cpp		
	    HistogramDraw.cpp		
	    HistogramItems.cpp		
	    HistogramOverflowPanel.cpp	
	    HistogramView.cpp		
	    History.cpp			
	    HistoryButtons.cpp		
	    ListEditor.cpp		
	    LocateFileTypeWindow.cpp	
	    LocateFilesWindow.cpp	
	    Logger.cpp			
	    MainWindow.cpp		
	    MainWindowHelp.cpp          
	    MainWindowLayout.cpp	
	    MainWindowMenus.cpp		
	    MainWindowUnpkg.cpp		
	    MessagePanel.cpp		
	    MimeCategorizer.cpp		
	    MimeCategory.cpp		
	    MimeCategoryConfigPage.cpp	
	    MountPoints.cpp		
	    OpenDirDialog.cpp		
	    OpenPkgDialog.cpp		
	    OutputWindow.cpp		
	    PacManPkgManager.cpp	
	    PanelMessage.cpp		
	    PathSelector.cpp		
	    PercentBar.cpp		
	    PercentileStats.cpp		
	    PkgFileListCache.cpp	
	    PkgFilter.cpp		
	    PkgInfo.cpp			
	    PkgManager.cpp		
	    PkgQuery.cpp		
	    PkgReader.cpp		
	    PopupLabel.cpp		
	    Process.cpp			
	    ProcessStarter.cpp		
	    Refresher.cpp		
	    RpmPkgManager.cpp		
	    SelectionModel.cpp		
	    Settings.cpp		
	    SettingsHelpers.cpp		
	    ShowUnpkgFilesDialog.cpp	
	    SizeColDelegate.cpp		
	    StdCleanup.cpp		
	    Subtree.cpp			
	    SysUtil.cpp			
	    SystemFileChecker.cpp	
	    Trash.cpp			
	    TreeWalker.cpp		
	    TreemapTile.cpp		
	    TreemapView.cpp		
	    UnpkgSettings.cpp		
	    UnreadableDirsWindow.cpp
)

set(HEADERS		 			
        #QDirStatApp.h		
	    ActionManager.h		
	    AdaptiveTimer.h		
	    Attic.h			
            BreadcrumbNavigator.h	
            BrokenLibc.h                
	    BucketsTableModel.h		
	    BusyPopup.h			
	    Cleanup.h			
	    CleanupCollection.h		
	    CleanupConfigPage.h		
	    ConfigDialog.h		
	    DataColumns.h		
	    DebugHelpers.h		
	    DelayedRebuilder.h		
	    DirInfo.h			
	    DirReadJob.h		
	    DirSaver.h			
	    DirTree.h			
	    DirTreeCache.h		
	    DirTreeFilter.h		
	    DirTreeModel.h		
	    DirTreePatternFilter.h	
	    DirTreePkgFilter.h		
	    DirTreeView.h		
	    DiscoverActions.h		
	    DotEntry.h			
	    DpkgPkgManager.h		
	    Exception.h			
	    ExcludeRules.h		
	    ExcludeRulesConfigPage.h	
	    ExistingDirCompleter.h	
	    ExistingDirValidator.h	
	    FileDetailsView.h		
	    FileInfo.h			
	    FileInfoIterator.h		
	    FileInfoSet.h		
	    FileInfoSorter.h		
	    FileMTimeStats.h		
	    FileSizeLabel.h		
	    FileSizeStats.h		
	    FileSizeStatsWindow.h	
	    FileSystemsWindow.h		
	    FileTypeStats.h		
	    GeneralConfigPage.h		
	    HeaderTweaker.h		
	    HistogramItems.h		
	    HistogramView.h		
	    ListEditor.h		
	    ListMover.h			
	    LocateFileTypeWindow.h	
	    LocateFilesWindow.h		
	    Logger.h			
	    MainWindow.h		
	    MessagePanel.h		
	    MimeCategorizer.h		
	    MimeCategory.h		
	    MimeCategoryConfigPage.h	
	    MountPoints.h		
	    OpenDirDialog.h		
	    OpenPkgDialog.h		
	    OutputWindow.h		
	    PacManPkgManager.h		
	    PanelMessage.h		
	    PathSelector.h		
	    PercentBar.h		
	    PercentileStats.h		
	    PkgFileListCache.h		
	    PkgFilter.h			
	    PkgInfo.h			
	    PkgManager.h		
	    PkgQuery.h			
	    PkgReader.h			
	    PopupLabel.h		
	    Process.h			
	    ProcessStarter.h		
	    Qt4Compat.h			
	    Refresher.h			
	    RpmPkgManager.h		
	    SelectionModel.h		
	    Settings.h			
	    SettingsHelpers.h		
	    ShowUnpkgFilesDialog.h	
	    SignalBlocker.h		
	    SizeColDelegate.h		
	    StdCleanup.h		
	    Subtree.h			
	    SysUtil.h			
	    SystemFileChecker.h		
	    Trash.h			
	    TreemapTile.h		
	    UnpkgSettings.cpp		
	    UnreadableDirsWindow.h	
	    FileAgeStats.h		
	    FileAgeStatsWindow.h	
	    FileSize.h			
	    FileTypeStatsWindow.h	
	    FormatUtil.h		
	    History.h			
	    HistoryButtons.h		
	    TreeWalker.h		
	    TreemapView.h		
	    Version.h

)

set(FORMS	 main-window.ui		   
	    cleanup-config-page.ui	   
	    config-dialog.ui		   
	    exclude-rules-config-page.ui   
	    file-age-stats-window.ui	   
	    file-details-view.ui	   
	    file-size-stats-window.ui	   
	    file-type-stats-window.ui	   
	    filesystems-window.ui	   
	    general-config-page.ui	   
	    locate-file-type-window.ui	   
	    locate-files-window.ui	   
	    message-panel.ui		   
	    mime-category-config-page.ui   
	    open-dir-dialog.ui		   
	    open-pkg-dialog.ui		   
	    output-window.ui		   
	    panel-message.ui		   
	    show-unpkg-files-dialog.ui	   
	    unreadable-dirs-window.ui
)

set(RESOURCES  icons.qrc)

#	    general-config-page.ui

add_library(QdirstatLib $SOURCES $HEADERS)

add_executable(qdirstat
	main.cpp
	QDirStatApp.cpp
	$HEADERS
	$FORMS
	$RESOURCES
)

target_link_libraries(qdirstat
	QdirstatLib
	Qt5::Widgets
	Qt5::Gui
	Qt5::Core
)

desktop.files = *.desktop
desktop.path  = $$INSTALL_PREFIX/share/applications

icons.files   = icons/qdirstat.png
icons.path    = $$INSTALL_PREFIX/share/icons/hicolor/32x32/apps

mac:ICON      = icons/qdirstat.icns
