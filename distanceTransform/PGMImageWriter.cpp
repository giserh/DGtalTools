/**
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/
/**
 * @file PGMImageWriter.cpp
 * @ingroup Tools
 * @author Nicolas Normand (\c Nicolas.Normand@polytech.univ-nantes.fr)
 * LUNAM Université, Université de Nantes, IRCCyN UMR CNRS 6597
 *
 * @date 2012/09/28
 *
 * LUTBasedNSDistanceTransform computes the 2D translated neighborhood-sequence
 * distance transform of a binary image. It reads the input images from its
 * standard input and writes the result to its standard output.
 *
 * This file is part of the DGtal library.
 */

#include "PGMImageWriter.h"
#include <boost/assert.hpp>

PGMImageWriter::PGMImageWriter(FILE* output, int plainFormat) :
_cols(0),
_plainFormat(plainFormat),
_output(output) {
}

void
PGMImageWriter::beginOfImage(int cols, int rows) {
    _cols = cols;
    _outputRow = pgm_allocrow(cols);
    BOOST_VERIFY(_outputRow != NULL);
    pgm_writepgminit(_output, cols, rows, 255, 1);
}

void
PGMImageWriter::endOfImage() {
    pgm_freerow(_outputRow);
}

void
PGMImageWriter::processRow(const GrayscalePixelType* inputRow) {
    for (int column = 0; column < _cols; ++column) {
	_outputRow[column] = inputRow[column];
    }
    pgm_writepgmrow(_output, _outputRow, _cols, 255, 1);
}
