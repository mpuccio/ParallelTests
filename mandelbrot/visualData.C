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

#include <TStyle.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <Riostream.h>


void visualData(TString str="data.dat") {
	gStyle->SetPalette(53);
	gStyle->SetOptStat(kFALSE);
	const int size = 1<<10;
	TCanvas *cv = new TCanvas("mdl","Mandelbrot set");
	cv->cd();
	cv->SetLogz();
	TH2F *h = new TH2F("mandelbrot","Mandelbrot set",size,-2,2,size,-2,2);

	ifstream f(str.Data());
	int count=0;
	float x;
	const float step = 4.f/size;
	while ( f>>x ) {
		if (x<=1) x=1;
		//cout << -2+(count/1024)*step << " " <<-2+(count%1024)*step << " " << x << endl;
		h->Fill(-2+(count/size+0.5f)*step,-2+(count%size+0.5f)*step,x);
		count++;
	}
	h->Draw("colz");
}
