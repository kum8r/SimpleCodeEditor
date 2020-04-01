#include "stylesheet.h"

StyleSheet::StyleSheet()
{
}

void *StyleSheet::setStyleSheet(QsciLexer *lexer, QString themeFileName, QsciScintilla *codeeditor)
{
    QFile themeFile(themeFileName);
    QFileInfo fileinfo(themeFileName);
    if (!themeFile.open(QIODevice::ReadOnly ))
    {
        return nullptr;
    }
    QXmlStreamReader xmlFile(&themeFile);

    if (lexer == nullptr)
    {
        while (!xmlFile.atEnd())
        {
            xmlFile.readNext();
            if (xmlFile.name() == "style")
            {
                if (xmlFile.attributes().value("name") == "Text")
                {
                    if (xmlFile.attributes().hasAttribute("foreground"))
                    {
                        codeeditor->setColor(QColor(xmlFile.attributes().value("foreground")));
                        codeeditor->setMarginsForegroundColor(QColor(xmlFile.attributes().value("foreground")));
                        codeeditor->setFoldMarginColors(QColor(xmlFile.attributes().value("foreground")), QColor(xmlFile.attributes().value("background")));
                    }
                    if (xmlFile.attributes().hasAttribute("background"))
                    {
                        codeeditor->setPaper(QColor(xmlFile.attributes().value("background")));
                        codeeditor->setPaper(QColor(xmlFile.attributes().value("background")));
                        codeeditor->setMarginsBackgroundColor(QColor(xmlFile.attributes().value("background")));
                    }
                }
            }
        }
        return nullptr;
    }

    while (!xmlFile.atEnd())
    {
        xmlFile.readNext();
        if (xmlFile.name() == "style")
        {
            if (xmlFile.attributes().value("name") == "Comment")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::Comment);
                if (xmlFile.attributes().hasAttribute("background"))
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::Comment);
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::Comment);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Text")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")));
                    lexer->setDefaultColor(QColor(xmlFile.attributes().value("foreground")));
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")));
                    lexer->setDefaultPaper(QColor(xmlFile.attributes().value("background")));
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "String")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::RawString);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::RawString);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::RawString);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Number")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::Number);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::Number);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::Number);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Keyword")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::Keyword);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::Keyword);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::Keyword);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Operator")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::Operator);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::Operator);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::Operator);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Occurrences.Unused")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::InactiveKeyword);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::InactiveKeyword);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::InactiveKeyword);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Type")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::Identifier);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::Identifier);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::Identifier);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "Preprocessor")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    lexer->setColor(QColor(xmlFile.attributes().value("foreground")), QsciLexerCPP::PreProcessor);
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    lexer->setPaper(QColor(xmlFile.attributes().value("background")), QsciLexerCPP::PreProcessor);
                }
                if (xmlFile.attributes().hasAttribute("italic"))
                {
                    if (xmlFile.attributes().value("italic") == "true")
                    {
                        font.setItalic(true);
                        lexer->setFont(font, QsciLexerCPP::PreProcessor);
                    }
                }
            }
            else if (xmlFile.attributes().value("name") == "LineNumber")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    codeeditor->setMarginsForegroundColor(QColor(xmlFile.attributes().value("foreground")));
                    codeeditor->setFoldMarginColors(QColor(xmlFile.attributes().value("foreground")), QColor(xmlFile.attributes().value("background")));
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    codeeditor->setMarginBackgroundColor(codeeditor->NumberMargin ,QColor(xmlFile.attributes().value("background")));
                }
            }
            else if (xmlFile.attributes().value("name") == "Selection")
            {
                if (xmlFile.attributes().hasAttribute("foreground"))
                {
                    codeeditor->setSelectionForegroundColor(QColor(xmlFile.attributes().value("foreground")));
                }
                if (xmlFile.attributes().hasAttribute("background"))
                {
                    codeeditor->setSelectionBackgroundColor(QColor(xmlFile.attributes().value("background")));
                }
            }

        }
    }
    return lexer;
}

void StyleSheet::setFont(QFont font)
{
    this->font = font;
}

void StyleSheet::setStyleForCommentAttribute()
{

}
