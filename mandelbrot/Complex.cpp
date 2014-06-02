/*************************************************************************    
 * 
 *  Author: Maximiliano Puccio
 * 
 *  Permission to use, copy, modify, and distribute this software
 *  and its documentation for any purpose and without fee is hereby
 *  granted, provided that the above copyright notice appear in all
 *  copies and that both that the copyright notice and this
 *  permission notice and warranty disclaimer appear in supporting
 *  documentation, and that the name of the author not be used in
 *  advertising or publicity pertaining to distribution of the
 *  software without specific, written prior permission.
 *
 *  The authors disclaim all warranties with regard to this
 *  software, including all implied warranties of merchantability
 *  and fitness.  In no event shall the author be liable for any
 *  special, indirect or consequential damages or any damages
 *  whatsoever resulting from loss of use, data or profits, whether
 *  in an action of contract, negligence or other tortious action,
 *  arising out of or in connection with the use or performance of
 *  this software.
 *
 *************************************************************************/

#include <Vc/Vc>
#include <fstream>
#include "Complex.h"
#include <iostream>

using namespace std;
using Vc::float_v;
using Vc::uint_v;
using Vc::uint_m;
using Vc::Memory;

typedef Complex<float_v> Z;

int main() {
	const int size = 1<<10;
	Memory<uint_v,size*size> output;

	const int iterations = 1000;
	cout << "Starting: "<<endl;
	cout << " float_v contains " <<  float_v::Size << " elemets!" << endl;
	cout << " output contains " << output.entriesCount() << " elements " << endl;
	cout << " output contains " << output.vectorsCount() << " vectors " << endl;
	for(int i=0; i<size; ++i) {
		const float_v xi = -2.f + 4.f*i/size;

		int count = 0;
		uint_m mask;
		for(uint_v j=uint_v::IndexesFromZero(); !(mask = j < size ).isEmpty(); j+=float_v::Size ) {
			const float_v yj = -2.f + (4.f/size)*static_cast<float_v>(j);
			Z z(xi,yj); 
			uint_v outv = uint_v::Zero();

			for(int k=0; k<iterations; ++k) {
				z = z.Mandel(xi,yj);
				uint_m m = z.SquaredNorm()<4;
				if ( m.isEmpty() ) break; 
				else ++outv(m);
			}
			output.vector(i*size/float_v::Size+count) = outv;
			count++;
		}
	}
	
	ofstream f("dataVc.dat",ios::out);
	for (size_t i = 0; i < output.entriesCount(); ++i) {
		if(i%size==0 && i!=0) f << endl;
	 	f << output.scalar(i) << "\t";
	}
	f.close();

	return 0;
}