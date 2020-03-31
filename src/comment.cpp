#include "comment.h"
#include <QTextStream>
#include "Qsci/qscilexercpp.h"
#include <QDebug>

Comment::Comment(QsciScintilla *editor) : editor(editor)
{
    setCommentType();
    if (editor->eolMode() == editor->EolWindows)
        line_ending = "\r\n";
    else
        line_ending = "\n";
}

QString Comment::commentString(QString text)
{
    QTextStream in(&text);
    QString line, commentedString;
    if (isMultiline)
    {
        text = multiline_comment_start +  text;
        text = text + " " + multiline_comment_end;
        return text;
    }
    while (!in.atEnd())
    {
        line = in.readLine();
        if (!isMultiline)
        {
            line = comment_string +  line + line_ending;
        }
        commentedString.append(line);
    }
    return commentedString;
}

QString Comment::unCommentString(QString text)
{
    QTextStream in(&text);
    QString line, commentedString;
    if (isMultiline)
    {
        text.remove(0, multiline_comment_start.count() + 1);
        int lastindex = text.lastIndexOf(multiline_comment_end);
        text = text.left(lastindex);
        return text;
    }
    while (!in.atEnd())
    {
        line = in.readLine();
        if (!isMultiline)
        {
            line.remove(0, comment_string.count());
        }
        commentedString.append(line);
    }
    return commentedString;
}

void Comment::toComment(QString text)
{
    _toComment = false;
    isMultiline = false;
    if (comment_string.isNull())
        isMultiline = true;
    if (!editor->hasSelectedText())
    {
        if (!text.startsWith(comment_string))
            _toComment = true;
        return;
    }
    if (text.startsWith(multiline_comment_start) || text.startsWith(comment_string))
    {
        if (text.startsWith(multiline_comment_start))
        {
            isMultiline = true;
            return;
        }
    }
    else
    {

        _toComment = true;
    }
     int selction_start = editor->SendScintilla(editor->SCI_GETSELECTIONSTART);
     int selction_end = editor->SendScintilla(editor->SCI_GETSELECTIONEND);
     int selectionstart_line = editor->SendScintilla(editor->SCI_LINEFROMPOSITION, selction_start);
     QString selText = editor->text(selectionstart_line);
     int selectionend_line = editor->SendScintilla(editor->SCI_LINEFROMPOSITION, selction_end);
     QString selendText = editor->text(selectionend_line);
     if (!selText.left(selction_start).isEmpty())
     {
         isMultiline = true;
     }
     if (!selendText.left(selction_end).isEmpty())
     {
         isMultiline = true;
     }
}

void Comment::setCommentType()
{
    qDebug() << editor->lexer()->lexer();
    if (strcmp(editor->lexer()->lexer(), "C++") || strcmp(editor->lexer()->lexer(), "Java") || strcmp(editor->lexer()->lexer(), "C")
          ||  strcmp(editor->lexer()->lexer(), "C#") || strcmp(editor->lexer()->lexer(), "JavaScript"))
    {
        comment_string = "//";
        multiline_comment_start = "/*";
        multiline_comment_end = "*/";
    }
    else if (strcmp(editor->lexer()->lexer(), "Bash"))
    {
        comment_string = "#";
        multiline_comment_start = ": '";
        multiline_comment_end = "'";
    }
    else if (strcmp(editor->lexer()->lexer(), "Batch"))
    {
        comment_string = "REM";
        multiline_comment_start = "goto comment ";
        multiline_comment_end = " :comment";
    }
    else if (strcmp(editor->lexer()->lexer(), "CMake"))
    {
        comment_string = "#";
        multiline_comment_start = "#[[";
        multiline_comment_end = "]]";
    }
    else if (strcmp(editor->lexer()->lexer(), "CoffeeScript"))
    {
        comment_string = "#";
        multiline_comment_start = "###";
        multiline_comment_end = "###";
    }
    else if (strcmp(editor->lexer()->lexer(), "Css"))
    {
        comment_string = nullptr;
        multiline_comment_start = "/*";
        multiline_comment_end = "*/";
    }
}

void Comment::toggleComment()
{
    QString SelectedText;
    if (editor->hasSelectedText())
    {
        SelectedText = editor->selectedText();
    }
    else
    {
        int pos =  editor->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
        int line = editor->SendScintilla(editor->SCI_LINEFROMPOSITION, pos);
        SelectedText = editor->text(line);
    }
    toComment(SelectedText);
    QString retText;
    if (_toComment)
    {
        retText = commentString(SelectedText);
    }
    else
    {
        retText = unCommentString(SelectedText);
    }
    if (editor->hasSelectedText())
    {
        editor->replaceSelectedText(retText);
    }
    else
    {
        int pos =  editor->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
        int line = editor->SendScintilla(editor->SCI_LINEFROMPOSITION, pos);
        SelectedText = editor->text(line);
        editor->setSelection(line, 0, line, SelectedText.count());
        editor->replaceSelectedText(retText);
    }
}

void Comment::comment()
{
    QString SelectedText;
    QString commentedString;
    if (editor->hasSelectedText())
    {
        SelectedText = editor->selectedText();
        toComment(SelectedText);
        commentedString =  commentString(SelectedText);
        editor->replaceSelectedText(commentedString);
    }
    else
    {
        int pos =  editor->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
        int line = editor->SendScintilla(editor->SCI_LINEFROMPOSITION, pos);
        SelectedText = editor->text(line);
        commentedString =  commentString(SelectedText);
        editor->setSelection(line, 0, line, SelectedText.count());
        editor->replaceSelectedText(commentedString);
    }

}

void Comment::unComment()
{
    QString SelectedText;
    if (editor->hasSelectedText())
    {
        SelectedText = editor->selectedText();
    }
    else
    {
        SelectedText = editor->text(editor->SendScintilla(editor->SCI_GETCURLINE));
    }
    unCommentString(SelectedText);
}

//void comment::togglecomment()
//{
//    {
////        QTextCursor cur = this->textCursor();
//        if (!cur.hasSelection())
//        {
//            selectLine();
//        }

//        int endSelection = cur.selectionEnd();
//        cur.setPosition(cur.selectionStart());
//        cur.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
//        this->setTextCursor(cur);

//        QString line = lineUnderCursor();

//        QString commentStart;
//        QString commentEnd;

//        if(fileType == "html" or fileType == "css"){

//            if(fileType == "html"){
//                commentStart = "<!--";
//                commentEnd = "-->";
//            }else{
//                commentStart = "/*";
//                commentEnd = "*/";
//            }

//            if(line.startsWith(commentStart)){
//                for(int i=0; i < commentStart.length(); i++){
//                    cur.deleteChar();
//                }
//                endSelection -= commentStart.length();

//                cur.setPosition(endSelection);
//                cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
//                this->setTextCursor(cur);
//                QString line = lineUnderCursor();

//                if(line.endsWith(commentEnd)){
//                    for(int i=0; i < commentEnd.length(); i++){
//                        cur.deletePreviousChar();
//                    }
//                }
//            }else{
//                cur.insertText(commentStart);
//                endSelection += commentStart.length();

//                cur.setPosition(endSelection);
//                cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
//                this->setTextCursor(cur);
//                QString line = lineUnderCursor();

//                if(!line.endsWith(commentEnd)){
//                    cur.insertText(commentEnd);
//                }
//            }

//        }else{
//            if(fileType == "py"){
//                commentStart = "#";
//            }else{
//                commentStart = "//";
//            }

//            if(line.startsWith(commentStart)){
//                for(int i=0; i < commentStart.length(); i++){
//                    cur.deleteChar();
//                }
//                endSelection -= commentStart.length();
//                cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);

//                while(cur.position() < endSelection){
//                    cur.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
//                    this->setTextCursor(cur);
//                    line = lineUnderCursor();

//                    if(line.startsWith(commentStart)){
//                        cur.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
//                        for(int i=0; i < commentStart.length(); i++){
//                            cur.deleteChar();
//                        }
//                        endSelection -= commentStart.length();

//                    }
//                    cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);

//                }

//            }else{
//                cur.insertText(commentStart);
//                endSelection += commentStart.length();
//                cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);

//                while(cur.position() < endSelection){
//                    cur.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor);
//                    this->setTextCursor(cur);
//                    line = lineUnderCursor();

//                    if(!line.startsWith(commentStart)){
//                        cur.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
//                        cur.insertText(commentStart);
//                        endSelection += commentStart.length();
//                    }

//                    cur.movePosition(QTextCursor::EndOfLine, QTextCursor::MoveAnchor);
//                }
//            }

//        }

//        this->setTextCursor(cur);
//    }

//}

