/*
 *   File name: IDirInfo.h
 *   Summary:	Support classes for QDirStat
 *   License:	GPL V2 - See file LICENSE for details.
 *
 *   Author:	Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */


#ifndef IDirInfo_h
#define IDirInfo_h
//#ifndef IDirInfo_h

#include "Logger.h"
#include "IFileInfo.h"
#include "DataColumns.h"


namespace QDirStat
{
    // Forward declarations
    class DirTree;

    /**
     * A more specialized version of @ref IFileInfo: This class can actually
     * manage children. The base class (@ref IFileInfo) has only stubs for the
     * respective methods to integrate seamlessly with the abstraction of a
     * file / directory tree; this class fills those stubs with life.
     *
     * @short directory item within a @ref DirTree.
     **/
    class IDirInfo: public IFileInfo
    {
    public:

#ifndef FI_INTERFACE
    /**
     * Default constructor.
     *
     * If "asDotEntry" is set, this will be used as the parent's
     * "dot entry", i.e. the pseudo directory that holds all the parent's
     * non-directory children. This is the only way to create a "dot
     * entry"!
     **/
		IDirInfo( DirTree * tree,
         IDirInfo * parent     = 0,
         bool	   asDotEntry = false );

    /**
     * Constructor from a stat buffer (i.e. based on an lstat() call).
     **/
    IDirInfo( const QString & filenameWithoutPath,
         struct stat   * statInfo,
         DirTree       * tree,
         IDirInfo       * parent = 0 );

    /**
     * Constructor from the bare neccessary fields
     * for use from a cache file reader
     **/
    IDirInfo( DirTree *	 tree,
         IDirInfo *	 parent,
         const QString & filenameWithoutPath,
         mode_t		 mode,
         FileSize	 size,
         time_t		 mtime );
#endif

    /**
     * Destructor.
     **/
	virtual ~IDirInfo() = 0;

    /**
     * Returns the total size in bytes of this subtree.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual FileSize totalSize() Q_DECL_OVERRIDE;

    /**
     * Returns the total size in blocks of this subtree.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual FileSize totalBlocks() Q_DECL_OVERRIDE;

    /**
     * Returns the total number of children in this subtree, excluding this
     * item.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual int totalItems() Q_DECL_OVERRIDE;

    /**
     * Returns the total number of subdirectories in this subtree,
     * excluding this item. Dot entries and "." or ".." are not counted.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual int totalSubDirs() Q_DECL_OVERRIDE;

    /**
     * Returns the total number of plain file children in this subtree,
     * excluding this item.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual int totalFiles() Q_DECL_OVERRIDE;

  

    /**
     * Returns 'true' if this had been excluded while reading.
     **/
	virtual bool isExcluded() const Q_DECL_OVERRIDE;
        //{ return _isExcluded; }

    /**
     * Set the 'excluded' status.
     **/
	virtual void setExcluded(bool excl = true) Q_DECL_OVERRIDE;
        //{ _isExcluded = excl; }

   

    /**
     * Returns true if this subtree is finished reading.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual bool isFinished() Q_DECL_OVERRIDE;

    /**
     * Returns true if this subtree is busy, i.e. it is not finished
     * reading yet.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual bool isBusy() Q_DECL_OVERRIDE;

    /**
     * Returns the number of pending read jobs in this subtree. When this
     * number reaches zero, the entire subtree is done.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
   /* virtual int pendingReadJobs() Q_DECL_OVERRIDE
        { return _pendingReadJobs;	}*/

    /**
     * Returns the first child of this item or 0 if there is none.
     * Use the child's next() method to get the next child.
     **/
  /*  virtual IFileInfo * firstChild() const Q_DECL_OVERRIDE
        { return _firstChild;	}
*/
 
    /**
     * Insert a child into the children list.
     *
     * The order of children in this list is absolutely undefined;
     * don't rely on any implementation-specific order.
     **/
    virtual void insertChild( IFileInfo *newChild ) Q_DECL_OVERRIDE;

    /**
     * Get the "Dot Entry" for this node if there is one (or 0 otherwise):
     * This is a pseudo entry that directory nodes use to store
     * non-directory children separately from directories. This way the end
     * user can easily tell which summary fields belong to the directory
     * itself and which are the accumulated values of the entire subtree.
     **/
  /*  virtual IDirInfo * dotEntry() const Q_DECL_OVERRIDE
        { return _dotEntry; }*/

    /**
     * Set a "Dot Entry". This makes sense for directories only.
     **/
    virtual void setDotEntry( IFileInfo *newDotEntry ) Q_DECL_OVERRIDE;

    ///**
    // * Returns true if this is a "Dot Entry". See @ref dotEntry() for
    // * details.
    // *
    // * Reimplemented - inherited from @ref IFileInfo.
    // **/
    //virtual bool isDotEntry() const Q_DECL_OVERRIDE
    //    { return _isDotEntry; }

    /**
     * Notification that a child has been added somewhere in the subtree.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual void childAdded( IFileInfo *newChild ) Q_DECL_OVERRIDE;

    /**
     * Remove a child from the children list.
     *
     * IMPORTANT: This MUST be called just prior to deleting an object of
     * this class. Regrettably, this cannot simply be moved to the
     * destructor: Important parts of the object might already be destroyed
     * (e.g., the virtual table - no more virtual methods).
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual void unlinkChild( IFileInfo *deletedChild ) Q_DECL_OVERRIDE;

    /**
     * Notification that a child is about to be deleted somewhere in the
     * subtree.
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual void deletingChild( IFileInfo *deletedChild ) Q_DECL_OVERRIDE;

    /**
     * Notification of a new directory read job somewhere in the subtree.
     **/
    void readJobAdded();

    /**
     * Notification of a finished directory read job somewhere in the
     * subtree.
     **/
    void readJobFinished();

    /**
     * Notification of an aborted directory read job somewhere in the
     * subtree.
     **/
    void readJobAborted();

    /**
     * Finalize this directory level after reading it is completed.
     * This does _not_ mean reading reading all subdirectories is completed
     * as well!
     *
     * Clean up unneeded dot entries.
     **/
    virtual void finalizeLocal();

    /**
     * Recursively finalize all directories from here on -
     * call finalizeLocal() recursively.
     **/
    void finalizeAll();

    /**
     * Get the current state of the directory reading process:
     *
     *    DirQueued	   waiting in the directory read queue
     *    DirReading   reading in progress
     *    DirFinished  reading finished and OK
     *    DirAborted   reading aborted upon user request
     *    DirError	   error while reading
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual DirReadState readState() const Q_DECL_OVERRIDE;

    /**
     * Set the state of the directory reading process.
     * See @ref readState() for details.
     **/
    void setReadState( DirReadState newReadState );

    /**
     * Return a list of (direct) children sorted by 'sortCol' and
     * 'sortOrder' (Qt::AscendingOrder or Qt::DescendingOrder).
     *
     * This might return cached information if the sort column and order
     * are the same as for the last call to this function, and there were
     * no children added or removed in the meantime.
     **/
    const IFileInfoList & sortedChildren( DataColumn	   sortCol,
                         Qt::SortOrder sortOrder );

    /**
     * Drop all cached information about children sorting.
     **/
    void dropSortCache( bool recursive = false );

    /**
     * Recursively delete all children, including the dot entry.
     **/
    void clear();

    /**
     * Reset to the same status like just after construction in preparation
     * of refreshing the tree from this point on:
     *
     * Delete all children if there are any, delete the dot entry's
     * children if there are any, restore the dot entry if it was removed
     * (e.g. in finalizeLocal()), set the read state to DirQueued.
     **/
    void reset();



    /**
     * Returns true if this is a @ref IDirInfo object.
     *
     * Don't confuse this with @ref isDir() which tells whether or not this
     * is a disk directory! Both should return the same, but you'll never
     * know - better be safe than sorry!
     *
     * Reimplemented - inherited from @ref IFileInfo.
     **/
    virtual bool isDirInfo() const Q_DECL_OVERRIDE
        { return true; }


    protected:

    /**
     * Recursively recalculate the summary fields when they are dirty.
     *
     * This is a _very_ expensive operation since the entire subtree may
     * recursively be traversed.
     **/
    void recalc();

    /**
     * Clean up unneeded / undesired dot entries:
     * Delete dot entries that don't have any children,
     * reparent dot entry children to the "real" (parent) directory if
     * there are not subdirectory siblings at the level of the dot entry.
     **/
    void cleanupDotEntries();


    //
    // Data members
    //
#ifndef FI_INTERFACE
    bool		_isDotEntry:1;		// Flag: is this entry a "dot entry"?
    bool		_isMountPoint:1;	// Flag: is this a mount point?
    bool		_isExcluded:1;		// Flag: was this directory excluded?
    bool		_summaryDirty:1;	// dirty flag for the cached values
    bool		_deletingAll:1;		// Deleting complete children tree?
    bool		_locked:1;		// App lock
    bool		_touched:1;		// App 'touch' flag
    int		_pendingReadJobs;	// number of open directories in this subtree

    // Children management

    IFileInfo *	_firstChild;		// pointer to the first child
    IDirInfo	 *	_dotEntry;		// pseudo entry to hold non-dir children

    // Some cached values

    FileSize	_totalSize;
    FileSize	_totalBlocks;
    int		_totalItems;
    int		_totalSubDirs;
    int		_totalFiles;
    time_t		_latestMtime;

    IFileInfoList *	_sortedChildren;
    DataColumn	_lastSortCol;
    Qt::SortOrder	_lastSortOrder;

    DirReadState	_readState;


    private:

    void init();
#endif

    };	// class IDirInfo

}	// namespace QDirStat


#endif // ifndef IDirInfo_h

