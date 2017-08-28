/***************************************************************************
 *   Copyright (C) 2008 by Danny Tonidandel   *
 *   tonidandel@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <iostream>
#include <cstdlib>
#include<pvm3.h>

using namespace std;


int main(int argc, char *argv[])
{
	int numt, tid;
	char buf[100];


	cout << "***********************************************" <<endl;
	cout << "*                                             *" <<endl;
	cout << "*         Ola Escravos! Voces estao ai?       *" <<endl;
	cout << "*              Eu sou BEOWULF!!               *"<<endl;
	cout << "***********************************************" <<endl;
	cout << endl;
	printf ( "Minha tarefa é =  %x\n", pvm_mytid() );
	cout << endl;



/* Da função pvm_spawn
O argumento 1 indica o nome do arquivo separado
O terceiro argumento(flag) indica opções de disparo (0 = o PVM decide em quem disparar a tarefa; 1 = o argumento seguinte(where) será o nome do computador) 
Se o terceiro e quarto argumentos forem, 0 e Null respectivamente, o PVM dispara em toda máquina virtual;
*/
//	numt = pvm_spawn ( "escravo1", NULL, 1, "labsister02.em.ufop.br", 1, &tid );
	for(int conta=0; conta<3; conta++)
	{
		numt = pvm_spawn ( "escravo1", NULL, 0, NULL, 1, &tid );
		numt = pvm_recv ( -1, -1 );
		/*Argumentos da função pvm_recv: A -1 in msgtag or tid matches anything. This allows the user the following options. If tid = -1 and msgtag is defined by the user, then pvm_recv will accept a message from any process which has a matching msgtag. If msgtag = -1 and tid is defined by the user, then pvm_recv will accept any message that is sent from process tid. If tid = -1 and msgtag = -1, then pvm_recv will accept any message from any process.*/
		pvm_bufinfo ( numt, ( int* ) 0, ( int* ) 0, &tid );
		pvm_upkstr ( buf );
		printf ("Sim, tarefa disparada =  %x. Eu sou o escravo %s\n", tid, buf );
		cout << endl;
		
	}
	cout << endl << "número de tarefas disparadas = " << numt << endl;
	pvm_exit();

  return EXIT_SUCCESS;
}
