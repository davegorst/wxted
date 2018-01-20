#ifndef TTXLINE_H
#define TTXLINE_H
#include <iostream>
#include <string>
#include <cstdint>

#include "ttxcodes.h"

/** TTXLine - a single line of teletext
 *  The line is always stored in 40 bytes in transmission ready format
 * (but with the parity bit set to 0).
 */

class TTXLine
{
    public:
        /** Constructors */
        TTXLine();
        TTXLine(std::string const& line);
        // TTXLine(std::string const& line);
        /** Default destructor */
        virtual ~TTXLine();


        /** Set m_textline
         * \param val New value to set
         */
        void Setm_textline(std::string const& val);

        /** Access m_textline
         * \return The current value of m_textline
         */
        std::string GetLine();

        /** True if the line is double height
         * @todo This is not good enough. Need to know the state at a particular point on a line. Add a character position parameter.
         * @param xLoc Location of the character we want to know if it is double height. (default 39)
         */
        bool IsDoubleHeight(int xLoc);

        /**
         * @brief Check if the line is blank so that we don't bother to write it to the file.
         * @return true is the line is blank
         */
        bool IsBlank();

        /** Place a character in a line. Must be an actual teletext code.
         *  Bit 7 will be stripped off.
         * \return previous character at that location (for undo)
         */
        char SetCharAt(int x,int code);

        /** Get one character from this line.
         *  If there is no data set then return a space
         */
        char GetCharAt(int xLoc);


        /** Return the line with control codes mapped for writing to a file
         * \return The mapped line
         */
        std::string GetMappedline();
        /** GetMappedLine7bit - returns a string with text file-safe mappings applied.
         * Escape to 7 bit (required by Javascript Droidfax)
         */
        std::string GetMappedline7bit();

        /** Determine if a location on the line is in alpha or graphics mode
         * \param loc The column address to look at
         * \return true if the character position at loc is in an alpha context
         */
        bool IsAlphaMode(int loc);

        /** Clear the current line. (Used by CTRL-DEL)
         */
        void ClearLine(){m_textline="                                        ";};

    protected:
    private:
        std::string validate(std::string const& test);
        unsigned int m_Counter; //!< Member variable "m_Counter"
        std::string m_textline;

};

#endif // TTXLINE_H
