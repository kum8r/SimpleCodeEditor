#ifndef COMMENT_H
#define COMMENT_H

#include <QObject>
#include "Qsci/qsciscintilla.h"

class comment
{
public:
    comment(QsciScintilla *editor);
    void getcodeeditor(QsciScintilla *editor);
    void toggleComment();
    void Comment();
    void unComment();

private:
    QString comment_string, line_ending, multiline_comment_start, multiline_comment_end;
    QsciScintilla *editor;
    bool isMultiline, _toComment;

    QString commentString(QString text);
    QString unCommentString(QString text);
    void toComment(QString text);
    void setCommentType();
};

#endif // COMMENT_H
