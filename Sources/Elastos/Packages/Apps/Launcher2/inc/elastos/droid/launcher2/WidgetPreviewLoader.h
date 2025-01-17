//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef  __ELASTOS_DROID_LAUNCHER2_WIDGETPREVIEWLOADER_H__
#define  __ELASTOS_DROID_LAUNCHER2_WIDGETPREVIEWLOADER_H__

#include "_Elastos.Droid.Launcher2.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/launcher2/IconCache.h"
#include "elastos/droid/database/sqlite/SQLiteOpenHelper.h"
#include "elastos/droid/os/AsyncTask.h"
#include "Elastos.Droid.AppWidget.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Database.h"
#include "Elastos.Droid.Graphics.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.CoreLibrary.Core.h"
#include "Elastos.CoreLibrary.Utility.h"
#include <elastos/core/Object.h>
#include "R.h"

using Elastos::Droid::AppWidget::IAppWidgetProviderInfo;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::Pm::IResolveInfo;
using Elastos::Droid::Content::Pm::IPackageManager;
using Elastos::Droid::Database::Sqlite::ISQLiteDatabase;
using Elastos::Droid::Database::Sqlite::SQLiteOpenHelper;
using Elastos::Droid::Graphics::IBitmap;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Os::AsyncTask;
using Elastos::Core::Object;
using Elastos::Utility::IHashMap;
using Elastos::Utility::IHashSet;
using Elastos::Utility::IArrayList;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

// TODO: we don't have SoftReference, use StrongReference instead
class SoftReferenceThreadLocal : public Object
{
public:
    SoftReferenceThreadLocal();

    CARAPI_(void) Set(
        /* [in] */ IInterface* t);

    CARAPI_(AutoPtr<IInterface>) Get();

protected:
    virtual CARAPI_(AutoPtr<IInterface>) InitialValue() = 0;

private:
    pthread_key_t mThreadLocal;
};

class CanvasCache : public SoftReferenceThreadLocal
{
protected:
    //@Override
    CARAPI_(AutoPtr<IInterface>) InitialValue();
};

class PaintCache : public SoftReferenceThreadLocal
{
protected:
    //@Override
    CARAPI_(AutoPtr<IInterface>) InitialValue();
};

class BitmapCache : public SoftReferenceThreadLocal
{
protected:
    //@Override
    CARAPI_(AutoPtr<IInterface>) InitialValue();
};

class RectCache : public SoftReferenceThreadLocal
{
protected:
    //@Override
    CARAPI_(AutoPtr<IInterface>) InitialValue();
};

class BitmapFactoryOptionsCache : public SoftReferenceThreadLocal
{
protected:
    //@Override
    CARAPI_(AutoPtr<IInterface>) InitialValue();
};

class WidgetPreviewLoader
    : public Object
    , public IWidgetPreviewLoader
{
private:
    class MyAsyncTask2;

public:
    class CacheDb
        : public SQLiteOpenHelper
        , public IWidgetPreviewLoaderCacheDb
    {
    public:
        CAR_INTERFACE_DECL();

        CacheDb(
            /* [in] */ IContext* context);

        //@Override
        CARAPI OnCreate(
            /* [in] */ ISQLiteDatabase* db);

        //@Override
        CARAPI OnUpgrade(
            /* [in] */ ISQLiteDatabase* db,
            /* [in] */ Int32 oldVersion,
            /* [in] */ Int32 newVersion);

    private:
        friend class MyAsyncTask2;
        friend class WidgetPreviewLoader;

        const static Int32 DB_VERSION;
        const static String DB_NAME;
        const static String TABLE_NAME;
        const static String COLUMN_NAME;
        const static String COLUMN_SIZE;
        const static String COLUMN_PREVIEW_BITMAP;
        AutoPtr<IContext> mContext;
    };

private:
    class MyAsyncTask
        : public AsyncTask
    {
    public:
        MyAsyncTask(
            /* [in] */ IInterface* o,
            /* [in] */ IBitmap* bitmap,
            /* [in] */ WidgetPreviewLoader* host);

        CARAPI DoInBackground(
            /* [in] */ ArrayOf<IInterface*>* params,
            /* [out] */ IInterface** result);

    private:
        IInterface* mO;
        IBitmap* mGeneratedPreview;
        WidgetPreviewLoader* mHost;
    };

    class MyAsyncTask2
        : public AsyncTask
    {
    public:
        MyAsyncTask2(
            /* [in] */ CacheDb* cacheDb,
            /* [in] */ const String& packageName);

        CARAPI DoInBackground(
            /* [in] */ ArrayOf<IInterface*>* params,
            /* [out] */ IInterface** result);

    private:
        CacheDb* mCacheDb;
        String mPackageName;
    };

public:
    CAR_INTERFACE_DECL();

    WidgetPreviewLoader();

    CARAPI constructor(
        /* [in] */ ILauncher* launcher);

    CARAPI RecreateDb();

    CARAPI SetPreviewSize(
        /* [in] */ Int32 previewWidth,
        /* [in] */ Int32 previewHeight,
        /* [in] */ IPagedViewCellLayout* widgetSpacingLayout);

    CARAPI GetPreview(
        /* [in] */ IInterface* o,
        /* [out] */ IBitmap** bitmap);

    CARAPI RecycleBitmap(
        /* [in] */ IInterface* o,
        /* [in] */ IBitmap* bitmapToRecycle);

    static CARAPI RemoveFromDb(
        /* [in] */ CacheDb* cacheDb,
        /* [in] */ const String& packageName);

    CARAPI GeneratePreview(
        /* [in] */ IInterface* info,
        /* [in] */ IBitmap* preview,
        /* [out] */ IBitmap** bitmap);

    CARAPI GenerateWidgetPreview(
        /* [in] */ IAppWidgetProviderInfo* info,
        /* [in] */ IBitmap* preview,
        /* [out] */ IBitmap** bitmap);

    CARAPI MaxWidthForWidgetPreview(
        /* [in] */ Int32 spanX,
        /* [out] */ Int32* width);

    CARAPI MaxHeightForWidgetPreview(
        /* [in] */ Int32 spanY,
        /* [out] */ Int32* height);

    CARAPI GenerateWidgetPreview(
        /* [in] */ IAppWidgetProviderInfo* info,
        /* [in] */ Int32 cellHSpan,
        /* [in] */ Int32 cellVSpan,
        /* [in] */ Int32 maxPreviewWidth,
        /* [in] */ Int32 maxPreviewHeight,
        /* [in] */ IBitmap* preview,
        /* [in] */ ArrayOf<Int32>* preScaledWidthOut,
        /* [out] */ IBitmap** bitmap);

    static CARAPI_(void) RenderDrawableToBitmap(
        /* [in] */ IDrawable* d,
        /* [in] */ IBitmap* bitmap,
        /* [in] */ Int32 x,
        /* [in] */ Int32 y,
        /* [in] */ Int32 w,
        /* [in] */ Int32 h);

private:
    static CARAPI_(String) GetObjectName(
        /* [in] */ IInterface* o);

    CARAPI_(String) GetObjectPackage(
        /* [in] */ IInterface* o);

    CARAPI WriteToDb(
        /* [in] */ IInterface* o,
        /* [in] */ IBitmap* preview);

    CARAPI ClearDb();

    CARAPI ReadFromDb(
        /* [in] */ const String& name,
        /* [in] */ IBitmap* b,
        /* [out] */ IBitmap** bitmap);

    CARAPI GenerateShortcutPreview(
        /* [in] */ IResolveInfo* info,
        /* [in] */ Int32 maxWidth,
        /* [in] */ Int32 maxHeight,
        /* [in] */ IBitmap* preview,
        /* [out] */ IBitmap** bitmap);

    static CARAPI_(void) RenderDrawableToBitmap(
        /* [in] */ IDrawable* d,
        /* [in] */ IBitmap* bitmap,
        /* [in] */ Int32 x,
        /* [in] */ Int32 y,
        /* [in] */ Int32 w,
        /* [in] */ Int32 h,
        /* [in] */ Float scale);

private:
    static const String TAG;
    static const String ANDROID_INCREMENTAL_VERSION_NAME_KEY;

    Int32 mPreviewBitmapWidth;
    Int32 mPreviewBitmapHeight;
    String mSize;
    AutoPtr<IContext> mContext;
    ILauncher* mLauncher;
    AutoPtr<IPackageManager> mPackageManager;
    AutoPtr<IPagedViewCellLayout> mWidgetSpacingLayout;

    // Used for drawing shortcut previews
    AutoPtr<BitmapCache> mCachedShortcutPreviewBitmap;
    AutoPtr<PaintCache> mCachedShortcutPreviewPaint;
    AutoPtr<CanvasCache> mCachedShortcutPreviewCanvas;

    // Used for drawing widget previews
    AutoPtr<CanvasCache> mCachedAppWidgetPreviewCanvas;
    AutoPtr<RectCache> mCachedAppWidgetPreviewSrcRect;
    AutoPtr<RectCache> mCachedAppWidgetPreviewDestRect;
    AutoPtr<PaintCache> mCachedAppWidgetPreviewPaint;
    String mCachedSelectQuery;
    AutoPtr<BitmapFactoryOptionsCache> mCachedBitmapFactoryOptions;

    Int32 mAppIconSize;
    Int32 mProfileBadgeSize;
    Int32 mProfileBadgeMargin;

    AutoPtr<IIconCache> mIconCache;

    const Float sWidgetPreviewIconPaddingPercentage;

    AutoPtr<IWidgetPreviewLoaderCacheDb> mDb;

    AutoPtr<IHashMap> mLoadedPreviews;
    Object mLoadedPreviewsLock;
    AutoPtr<IArrayList> mUnusedBitmaps;
    Object mUnusedBitmapsLock;
    static AutoPtr<IHashSet> sInvalidPackages;
    static Object sInvalidPackagesLock;

    static const String WIDGET_PREFIX;
    static const String SHORTCUT_PREFIX;
};

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_LAUNCHER2_WIDGETPREVIEWLOADER_H__
