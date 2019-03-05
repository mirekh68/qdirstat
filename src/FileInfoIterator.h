/*
 *   File name: IFileInfoIterator.h
 *   Summary:	Support classes for QDirStat - DirTree iterators
 *   License:	GPL V2 - See file LICENSE for details.
 *
 *   Author:	Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */


#ifndef IFileInfoIterator_h
#define IFileInfoIterator_h


#include <QList>
#include "IFileInfo.h"


namespace QDirStat
{
    /**
     * Iterator class for children of a @ref IFileInfo object. For optimum
     * performance, this iterator class does NOT return children in any
     * specific sort order.
     *
     * Sample usage:
     *
     *	  IFileInfoIterator it( node );
     *
     *	  while ( *it )
     *	  {
     *	     logDebug() << *it << ":\t" << (*it)->totalSize() << endl;
     *	     ++it;
     *	  }
     *
     * This will output the URL (path+name) and the total size of each (direct)
     * subdirectory child and each (direct) file child of 'node'.
     * Notice: This does not recurse into subdirectories!
     *
     * @short (unsorted) iterator for @ref IFileInfo children.
     **/
    class IFileInfoIterator
    {
    public:
    /**
     * Constructor: Initialize an iterator object to iterate over the
     * children of 'parent' (unsorted!). The dot entry is treated as a
     * subdirectory.
     **/
    IFileInfoIterator( IFileInfo * parent );

    protected:
    /**
     * Alternate constructor to be called from derived classes: Those can
     * choose not to call next() in the constructor.
     **/
    IFileInfoIterator( IFileInfo * parent,
              bool	     callNext );

    private:
    /**
     * Internal initialization called from any constructor.
     **/
    void init( IFileInfo * parent,
           bool	      callNext );

    public:

    /**
     * Return the current child object or 0 if there is no more.
     * Same as @ref operator*() .
     **/
    IFileInfo * current() { return _current; }

    /**
     * Return the current child object or 0 if there is no more.
     * Same as @ref current().
     **/
    IFileInfo * operator*() { return current(); }

    /**
     * Advance to the next child. Same as @ref operator++().
     **/
    void next();

    /**
     * Advance to the next child. Same as @ref next().
     **/
    void operator++() { next(); }

    /**
     * Return the number of items that will be processed.
     * This is an expensive operation.
     **/
    int count();


    protected:

    IFileInfo *	_parent;
    IFileInfo *	_current;
    bool		_directChildrenProcessed;
    bool		_dotEntryProcessed;

    };	// class IFileInfoIterator


    class IFileInfoSortedBySizeIterator
    {
    public:

    /**
     * Constructor. Children below 'minSize' will be ignored by this iterator.
     **/
    IFileInfoSortedBySizeIterator( IFileInfo	    * parent,
                      FileSize	      minSize	= 0,
                      Qt::SortOrder   sortOrder = Qt::DescendingOrder );

    /**
     * Return the current child object or 0 if there is no more.
     * Same as @ref operator*() .
     **/
    IFileInfo * current();

    /**
     * Return the current child object or 0 if there is no more.
     * Same as @ref current().
     **/
    IFileInfo * operator*() { return current(); }

    /**
     * Advance to the next child. Same as @ref operator++().
     **/
    void next();

    /**
     * Advance to the next child. Same as @ref next().
     **/
    void operator++() { next(); }

    /**
     * Return the number of items that will be processed.
     **/
    int count() { return _sortedChildren.size(); }

    protected:

    IFileInfoList _sortedChildren;
    int	     _currentIndex;
    }; //

} // namespace QDirStat


#endif // ifndef IFileInfoIterator_h

