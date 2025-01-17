elog("====CalculatorEditText.js====begin====");

module.exports = function(aoElastos, aoActivity){
    var FullClassName = "Elastos.DevSamples.Node.JSCalculator.CalculatorEditText";
    var ShortClassName = FullClassName.split(".").pop();

//--------common definition----begin----
    var CObject = aoElastos.CObject;

    var CString = aoElastos.Core.CString;
    var Droid_New = aoElastos.Droid.New;
    var Core_New = aoElastos.Core.New;

    var R = aoElastos.Application.R;

    var oActivity = aoActivity.ActivityInstance;
    var oHandler = aoActivity.ActivityHandler;

    var IView__VISIBLE = 0x00000000;
    var IView__INVISIBLE = 0x00000004;
    var IView__GONE = 0x00000008;
    var IMotionEvent__ACTION_DOWN = 0;
    var IMotionEvent__ACTION_UP = 1;
    var IContext__LAYOUT_INFLATER_SERVICE = "layout_inflater";

//--------common definition----end----

//--------.java----begin----

// /*
//  * Copyright (C) 2014 The Android Open Source Project
//  *
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at
//  *
//  *   http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
// */

// package com.android.calculator2;

// import android.content.Context;
// import android.content.res.TypedArray;
// import android.graphics.Paint;
// import android.graphics.Paint.FontMetricsInt;
// import android.graphics.Rect;
// import android.os.Parcelable;
// import android.text.method.ScrollingMovementMethod;
// import android.text.TextPaint;
// import android.util.AttributeSet;
// import android.util.TypedValue;
// import android.view.ActionMode;
// import android.view.Menu;
// import android.view.MenuItem;
// import android.view.MotionEvent;
// import android.widget.EditText;
class EditText {}
// import android.widget.TextView;

// public class CalculatorEditText extends EditText {
class _CalculatorEditText extends EditText {

//     private final static ActionMode.Callback NO_SELECTION_ACTION_MODE_CALLBACK =
//             new ActionMode.Callback() {
    static get NO_SELECTION_ACTION_MODE_CALLBACK() {
        if (CalculatorEditText._NO_SELECTION_ACTION_MODE_CALLBACK_) return CalculatorEditText._NO_SELECTION_ACTION_MODE_CALLBACK;
        CalculatorEditText._NO_SELECTION_ACTION_MODE_CALLBACK = new class _temp {

//         @Override
//         public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
            onActionItemClicked(mode, item) {
//             return false;
                return false;
            }

//         @Override
//         public boolean onCreateActionMode(ActionMode mode, Menu menu) {
            onCreateActionMode(mode, menu) {
//             // Prevents the selection action mode on double tap.
//             return false;
                return false;
            }

//         @Override
//         public void onDestroyActionMode(ActionMode mode) {
            onDestroyActionMode(mode) {
            }

//         @Override
//         public boolean onPrepareActionMode(ActionMode mode, Menu menu) {
            onPrepareActionMode(mode, menu) {
//             return false;
                return false;
            }
        }();

        return CalculatorEditText._NO_SELECTION_ACTION_MODE_CALLBACK;
    }   //NO_SELECTION_ACTION_MODE_CALLBACK

//     private final float mMaximumTextSize;
//     private final float mMinimumTextSize;
//     private final float mStepTextSize;

//     // Temporary objects for use in layout methods.
//     private final Paint mTempPaint = new TextPaint();
    get mTempPaint() {
        if (this._mTempPaint_) return this._mTempPaint;
        this._mTempPaint_ = true;
        this._mTempPaint = Droid_New("Elastos.Droid.Text.CTextPaint");
        return this._mTempPaint;
    }

//     private final Rect mTempRect = new Rect();
    get mTempRect() {
        if (this._mTempRect_) return this._mTempRect;
        this._mTempRect_ = true;
        this._mTempRect = Droid_New("Elastos.Droid.Graphics.CRect");
        return this._mTempRect;
    }

//     private int mWidthConstraint = -1;
    get mWidthConstraint() {return -1;}

//     private OnTextSizeChangeListener mOnTextSizeChangeListener;

//     public CalculatorEditText(Context context) {
//         this(context, null);
//     }

//     public CalculatorEditText(Context context, AttributeSet attrs) {
//         this(context, attrs, 0);
//     }

//     public CalculatorEditText(Context context, AttributeSet attrs, int defStyle) {
    OnCreate(_this, context, attrs, defStyle) {
            elog(FullClassName + "========OnCreate begin========");

            attrs = attrs || null;
            defStyle = defStyle || 0;

            //_super = _this.GetSuperObject();

//         super(context, attrs, defStyle);
            _this._constructor(context, attrs, defStyle);

//         final TypedArray a = context.obtainStyledAttributes(
//                 attrs, R.styleable.CalculatorEditText, defStyle, 0);
            var a = context.ObtainStyledAttributes(
                    attrs, R.styleable.CalculatorEditText, defStyle, 0);

//         mMaximumTextSize = a.getDimension(
//                 R.styleable.CalculatorEditText_maxTextSize, getTextSize());
            this.mMaximumTextSize = a.GetDimension(
                    R.styleable.CalculatorEditText_maxTextSize, _this.GetTextSize());
//         mMinimumTextSize = a.getDimension(
//                 R.styleable.CalculatorEditText_minTextSize, getTextSize());
            this.mMinimumTextSize = a.GetDimension(
                    R.styleable.CalculatorEditText_minTextSize, _this.GetTextSize());
//         mStepTextSize = a.getDimension(R.styleable.CalculatorEditText_stepTextSize,
//                 (mMaximumTextSize - mMinimumTextSize) / 3);
            this.mStepTextSize = a.GetDimension(
                    R.styleable.CalculatorEditText_stepTextSize,
                    (this.mMaximumTextSize - this.mMinimumTextSize) / 3);

//         a.recycle();
            a.Recycle();

//         setCustomSelectionActionModeCallback(NO_SELECTION_ACTION_MODE_CALLBACK);
            _this.SetCustomSelectionActionModeCallback(this.NO_SELECTION_ACTION_MODE_CALLBACK);

//         if (isFocusable()) {
            if (_this.IsFocusable()) {
//             setMovementMethod(ScrollingMovementMethod.getInstance());
                _this.SetMovementMethod(Droid_New("Elastos.Droid.Text.Method.CScrollingMovementMethodHelper").GetInstance());
//         }
            }
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, mMaximumTextSize);
            var TypedValue__COMPLEX_UNIT_PX = 0; //TODO
            _this.SetTextSize(TypedValue__COMPLEX_UNIT_PX, this.mMaximumTextSize);

//         setMinHeight(getLineHeight() + getCompoundPaddingBottom() + getCompoundPaddingTop());
            _this.SetMinHeight(_this.GetLineHeight() + _this.GetCompoundPaddingBottom() + _this.GetCompoundPaddingTop());

            elog(FullClassName + "========OnCreate end========");
    }

//     @Override
//     public boolean onTouchEvent(MotionEvent event) {
    OnTouchEvent(_this, event, result) {
            elog(FullClassName + "========OnTouchEvent begin========");

//         if (event.getActionMasked() == MotionEvent.ACTION_UP) {
            if (event.GetActionMasked() == IMotionEvent__ACTION_UP) {
//             // Hack to prevent keyboard and insertion handle from showing.
//             cancelLongPress();
                _this.CancelLongPress();
//         }
            }
//         return super.onTouchEvent(event);
            result.data = _this._OnTouchEvent(event);

            elog(FullClassName + "========OnTouchEvent end========");
    }

//     @Override
//     protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    OnMeasure(_this, widthMeasureSpec, heightMeasureSpec) {
            elog(FullClassName + "========OnMeasure begin========");

//         super.onMeasure(widthMeasureSpec, heightMeasureSpec);
            _super.onMeasure(widthMeasureSpec, heightMeasureSpec);

//         mWidthConstraint =
//                 MeasureSpec.getSize(widthMeasureSpec) - getPaddingLeft() - getPaddingRight();
            this.mWidthConstraint =
                    MeasureSpec.GetSize(widthMeasureSpec) - this.getPaddingLeft() - this.getPaddingRight();
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, getVariableTextSize(getText().toString()));
            var TypedValue__COMPLEX_UNIT_PX = 0;
            this.SetTextSize(_this, TypedValue__COMPLEX_UNIT_PX, this.GetVariableTextSize(_this, getText().toString()));

            elog(FullClassName + "========OnMeasure end========");
    }

//     @Override
//     public Parcelable onSaveInstanceState() {
    OnSaveInstanceState(_this, result) {
            elog(FullClassName + "========OnSaveInstanceState begin========");

//         super.onSaveInstanceState();
            _super.onSaveInstanceState();

//         // EditText will freeze any text with a selection regardless of getFreezesText() ->
//         // return null to prevent any state from being preserved at the instance level.
//         return null;
            result.data = null;

            elog(FullClassName + "========OnSaveInstanceState end========");
    }

//     @Override
//     protected void onTextChanged(CharSequence text, int start, int lengthBefore, int lengthAfter) {
    OnTextChanged(_this, text, start, lengthBefore, lengthAfter) {
            elog(FullClassName + "========OnTextChanged begin========");

//         super.onTextChanged(text, start, lengthBefore, lengthAfter);
            _this._OnTextChanged(text, start, lengthBefore, lengthAfter);

//         final int textLength = text.length();
            var textLength = text.GetLength();
//         if (getSelectionStart() != textLength || getSelectionEnd() != textLength) {
            if (_this.GetSelectionStart() != textLength || _this.GetSelectionEnd() != textLength) {
//             // Pin the selection to the end of the current text.
//             setSelection(textLength);
                _this.SetSelection(textLength);
//         }
            }
//         setTextSize(TypedValue.COMPLEX_UNIT_PX, getVariableTextSize(text.toString()));
            //TODO: const value in car interface definition
            //TODO: Elastos.Droid.Utility.TypedValue(ITypedValue).COMPLEX_UNIT_PXCOMPLEX_UNIT_PX
            var TypedValue__COMPLEX_UNIT_PX = 0;
            this.SetTextSize(_this, TypedValue__COMPLEX_UNIT_PX, this.GetVariableTextSize(_this, text.ToString()));

            elog(FullClassName + "========OnTextChanged end========");
    }

//     @Override
//     public void setTextSize(int unit, float size) {
    SetTextSize(_this, unit, size) {
            elog(FullClassName + "========SetTextSize begin========");

//         final float oldTextSize = getTextSize();
            var oldTextSize = _this.GetTextSize();

//         super.setTextSize(unit, size);
            _this._SetTextSize(unit, size);

//         if (mOnTextSizeChangeListener != null && getTextSize() != oldTextSize) {
            if (this.mOnTextSizeChangeListener != null && _this.GetTextSize() != oldTextSize) {
//             mOnTextSizeChangeListener.onTextSizeChanged(this, oldTextSize);
                this.mOnTextSizeChangeListener.onTextSizeChanged(this, oldTextSize);
//         }
            }
            elog(FullClassName + "========SetTextSize end========");
    }

//     public void setOnTextSizeChangeListener(OnTextSizeChangeListener listener) {
    SetOnTextSizeChangeListener(listener) {
//         mOnTextSizeChangeListener = listener;
            this.mOnTextSizeChangeListener = listener;
    }

//     public float getVariableTextSize(String text) {
    GetVariableTextSize(_this, text) {
            elog(FullClassName + "========GetVariableTextSize begin========");

//         if (mWidthConstraint < 0 || mMaximumTextSize <= mMinimumTextSize) {
            if (this.mWidthConstraint < 0 || this.mMaximumTextSize <= this.mMinimumTextSize) {
//             // Not measured, bail early.
//             return getTextSize();
                return _this.GetTextSize();
//         }
            }

//         // Capture current paint state.
//         mTempPaint.set(getPaint());
            mTempPaint.Set(_this.GetPaint());

//         // Step through increasing text sizes until the text would no longer fit.
//         float lastFitTextSize = mMinimumTextSize;
            var lastFitTextSize = this.mMinimumTextSize;
//         while (lastFitTextSize < mMaximumTextSize) {
            while (lastFitTextSize < this.mMaximumTextSize) {
//             final float nextSize = Math.min(lastFitTextSize + mStepTextSize, mMaximumTextSize);
                var nextSize = Math.min(lastFitTextSize + this.mStepTextSize, this.mMaximumTextSize);
//             mTempPaint.setTextSize(nextSize);
                mTempPaint.SetTextSize(nextSize);
//             if (mTempPaint.measureText(text) > mWidthConstraint) {
                if (mTempPaint.MeasureText(text) > mWidthConstraint) {
//                 break;
                    break;
//             } else {
                } else {
//                 lastFitTextSize = nextSize;
                    lastFitTextSize = nextSize;
//             }
                }
//         }
            }

            elog(FullClassName + "========GetVariableTextSize end========");

//         return lastFitTextSize;
            return lastFitTextSize;
    }

//     @Override
//     public int getCompoundPaddingTop() {
    GetCompoundPaddingTop(_this, result) {
            elog(FullClassName + "========GetCompoundPaddingTop begin========");

//         // Measure the top padding from the capital letter height of the text instead of the top,
//         // but don't remove more than the available top padding otherwise clipping may occur.
//         getPaint().getTextBounds("H", 0, 1, mTempRect);
            _this.GetPaint().GetTextBounds("H", 0, 1, this.mTempRect);

//         final FontMetricsInt fontMetrics = getPaint().getFontMetricsInt();
            var fontMetrics = _this.GetPaint().GetFontMetricsInt();
//         final int paddingOffset = -(fontMetrics.ascent + mTempRect.height());
            var paddingOffset = -(fontMetrics.GetDescent() + this.mTempRect.GetHeight());
//         return super.getCompoundPaddingTop() - Math.min(getPaddingTop(), paddingOffset);
            result.data = _this._GetCompoundPaddingTop() - Math.min(_this.GetPaddingTop(), paddingOffset);

            elog(FullClassName + "========GetCompoundPaddingTop end========");
    }

//     @Override
//     public int getCompoundPaddingBottom() {
    GetCompoundPaddingBottom(_this, result) {
            elog(FullClassName + "========GetCompoundPaddingBottom begin========");

//         // Measure the bottom padding from the baseline of the text instead of the bottom, but don't
//         // remove more than the available bottom padding otherwise clipping may occur.
//         final FontMetricsInt fontMetrics = getPaint().getFontMetricsInt();
            var fontMetrics = _this.GetPaint().GetFontMetricsInt();

//         return super.getCompoundPaddingBottom() - Math.min(getPaddingBottom(), fontMetrics.descent);
            //return _super.getCompoundPaddingBottom() - Math.min(getPaddingBottom(), fontMetrics.descent);
            result.data = _this._GetCompoundPaddingBottom() - Math.min(_this.GetPaddingBottom(), fontMetrics.GetDescent());

            elog(FullClassName + "========GetCompoundPaddingBottom end========");
    }

//     public interface OnTextSizeChangeListener {
//         void onTextSizeChanged(TextView textView, float oldSize);
//     }
}   //class _CalculatorEditText

//--------.java----end----

class CalculatorEditText extends _CalculatorEditText {
    OnCreate(_this, context, attrs, defStyle) {
        elog('====CalculatorEditText.js====::OnCreate.begin====');
        _this._constructor(context, attrs, defStyle);
        elog('====CalculatorEditText.js====::OnCreate.end====');
    }

    OnTextChanged(_this, text, start, lengthBefore, lengthAfter) {
        elog('====CalculatorEditText.js====::OnTextChanged.begin====');
        _this._OnTextChanged(text, start, lengthBefore, lengthAfter);
        elog('====CalculatorEditText.js====::OnTextChanged.end====');
    }

    OnMeasure(_this, widthMeasureSpec, heightMeasureSpec) {
        elog('====CalculatorEditText.js====::OnMeasure.begin====');
        _this._OnMeasure(widthMeasureSpec, heightMeasureSpec);
        elog('====CalculatorEditText.js====::OnMeasure.end====');
    }

    GetCompoundPaddingTop(_this, result) {
        elog('====CalculatorEditText.js====::GetCompoundPaddingTop.begin====');
        result.data = _this._GetCompoundPaddingTop();
        elog('====CalculatorEditText.js====::GetCompoundPaddingTop.end====');
    }

    GetCompoundPaddingBottom(_this, result) {
        elog('====CalculatorEditText.js====::GetCompoundPaddingBottom.begin====');
        result.data = _this._GetCompoundPaddingBottom();
        elog('====CalculatorEditText.js====::GetCompoundPaddingBottom.end====');
    }
}   //class CalculatorEditText

return new CalculatorEditText();

};  //module.exports

elog("====CalculatorEditText.js====end======");