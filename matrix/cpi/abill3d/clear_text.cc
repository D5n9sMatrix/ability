/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef CLEAR_TEXT
#define CLEAR_TEXT
#ifdef CLEAR_TEXT_EMPTY
QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE
QT_MODULE(Gui)
class QVariant;
class Q_GUI_EXPORT QClearText : public QDimText
{
public:
    QClearText();
    QClearText(const QDimText &);
    QClearText(int w, int h);
    explicit QClearText(const QSize &);
    explicit QClearText(const QString &fileName, const char *format=0);
    ~QClearText();
    QClearText &operator=(const QDimText &);
    inline void swap(QClearText &other) { QDimText::swap(other); } // prevent QClearText<->QDimText swaps
    operator QVariant() const;
    inline void clear() { fill(Qt::color0); }
    static QClearText fromImage(const QImage &image, Qt::ImageConversionFlags flags = Qt::AutoColor);
    static QClearText fromData(const QSize &size, const uchar *bits,
                            QImage::Format monoFormat = QImage::Format_MonoLSB);
    QClearText transformed(const QMatrix &) const;
    QClearText transformed(const QTransform &matrix) const;
#ifdef QT3_SUPPORT
    inline QT3_SUPPORT_CONSTRUCTOR QClearText(int w, int h, bool clear);
    inline QT3_SUPPORT_CONSTRUCTOR QClearText(const QSize &, bool clear);
    QT3_SUPPORT_CONSTRUCTOR QClearText(int w, int h, const uchar *bits, bool isXbitmap=false);
    QT3_SUPPORT_CONSTRUCTOR QClearText(const QSize &, const uchar *bits, bool isXbitmap=false);
    inline QT3_SUPPORT QClearText xForm(const QMatrix &matrix) const { return transformed(QTransform(matrix)); }
    QT3_SUPPORT_CONSTRUCTOR QClearText(const QImage &image) { *this = fromImage(image); }
    QT3_SUPPORT QClearText &operator=(const QImage &image) { *this = fromImage(image); return *this; }
#endif
    typedef QExplicitlySharedDataPointer<QDimTextData> DataPtr;
};
Q_DECLARE_SHARED(QClearText)
#ifdef QT3_SUPPORT
inline QClearText::QClearText(int w, int h, bool clear)
    : QDimText(QSize(w, h), 1)
{
    if (clear) this->clear();
}
inline QClearText::QClearText(const QSize &size, bool clear)
    : QDimText(size, 1)
{
    if (clear) this->clear();
}
#endif
QT_END_NAMESPACE
QT_END_HEADER
#endif // CLEAR_TEXT
#endif // CLEAR_TEXT_EMPTY
