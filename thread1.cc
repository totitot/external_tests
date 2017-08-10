#include "pthread.h"
#include "sys/types.h"
#include <cstdlib>
#include <string>
#include <iostream>

void *print_msg( void *msg );

int main( void ){
	pthread_t thread1, thread2;

	std::string message1("Thread 1\n");
	std::string message2("Thread 2\n");


	int iret1 = pthread_create( &thread1, NULL, print_msg, static_cast< void * > ( const_cast< char * >( message1.c_str() ) ) );
	if( iret1 ){
		std::cout << "Error iret1 return : " << iret1 << std::endl; 
		return( iret1 );
	}

	int iret2 = pthread_create( &thread2, NULL, print_msg, static_cast< void * > ( const_cast< char * >( message2.c_str() ) ) );
	if( iret2 ){
		std::cout << "Error iret2 return : " << iret2 << std::endl; 
		return( iret2 );
	}

	pthread_join( thread1, NULL );
	pthread_join( thread2, NULL );

	std::cout << "thread1 : " << iret1 << std::endl;
	std::cout << "thread2 : " << iret2 << std::endl;

	return( iret1 | iret2 );
}

void *print_msg( void *msg ){
	std::cout << static_cast< char * >( msg ) << std::endl;
	return NULL;
}
