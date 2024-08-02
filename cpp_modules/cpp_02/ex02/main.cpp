#include "Fixed.hpp"

int main( void )
{

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	
	// Fixed aa (2.5f);
	// Fixed bb (2);

	// std::cout << aa << " + " << bb << " 	 "<< (aa + bb) << "\n";
	// std::cout << aa << " - " << bb << " 	 "<< (aa - bb) << "\n";
	// std::cout << aa << " / " << bb << " 	 "<< (aa / bb) << "\n";

	// std::cout << aa << " == " << bb << " 	 "<< (aa == bb) << "\n";
	// std::cout << aa << " >= " << bb << " 	 "<< (aa >= bb) << "\n";
	// std::cout << aa << " <= " << bb << " 	 "<< (aa <= bb) << "\n";

	// std::cout << aa << " != " << bb << " 	 "<< (aa != bb) << "\n\n";

	// aa++;
	// std::cout << aa << " != " << bb << " 	 "<< (aa != bb) << "\n";

	// std::cout << aa << " >= " << bb << " 	 "<< (aa >= bb) << "\n";
	// std::cout << aa << " > " << bb << " 	 "<< (aa > bb) << "\n";
	// std::cout << aa << " <= " << bb << " 	 "<< (aa <= bb) << "\n";
	// std::cout << aa << " < " << bb << " 	 "<< (aa < bb) << "\n\n";


	// std::cout << aa-- <<"\n";
	// std::cout << aa << "\n";
	// std::cout << --aa <<"\n";

	return 0;
}
