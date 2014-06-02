/*************************************************************************    
 * 
 *  Author: Maximiliano Puccio
 * 
 *  PLEASE LOOK AT THE .cpp FILE FOR THE SOFTWARE LICENSE  
 *
 *************************************************************************/
 
#ifndef COMPLEX_H

template <typename Type> class Complex {
	public:

		Complex() : fImZ(),fImZ2(),fReZ(),fReZ2() {}
		Complex(Type reZ, Type imZ) : fImZ(imZ), fImZ2(imZ*imZ), fReZ(reZ), fReZ2(reZ*reZ) {} 	

		Complex Mandel(Type x, Type y) { return Complex(fReZ2-fImZ2+x, (fReZ+fReZ)*fImZ+y); }

		Type GetImZ() const { return fImZ; }
		Type GetReZ() const { return fReZ; }
		Type GetImZ2() const { return fImZ2; }
		Type GetReZ2() const { return fReZ2; }

		void SetImZ( Type imZ ) { fImZ=imZ; fImZ2=imZ*imZ; }
		void SetReZ( Type reZ ) { fReZ=reZ; fReZ2=reZ*reZ; }

		Type SquaredNorm() const { return fReZ2 + fImZ2; }

		Complex & operator+(Complex<Type> &add) { 
			Complex<Type> ret; 
			ret.SetReZ(fReZ + add.GetReZ()); 
			ret.SetImZ(fImZ + add.GetImZ()); 
			return ret; 
		}
		
		Complex & operator-(Complex<Type> &sub) { 
			Complex<Type> ret; 
			ret.SetReZ(fReZ - sub.GetReZ()); 
			ret.SetImZ(fImZ - sub.GetImZ()); 
			return ret; 
		}

		Complex & operator*(Complex<Type> &mul) { 
			Complex<Type> ret; 
			ret.SetReZ( fReZ * mul.GetReZ() - fImZ * mul.GetImZ() ); 
			ret.SetImZ( fReZ * mul.GetImZ() + fReZ * mul.GetImZ() ); 
			return ret; 
		}

	private: 
		Type fImZ, fImZ2;
		Type fReZ, fReZ2;
};


#endif