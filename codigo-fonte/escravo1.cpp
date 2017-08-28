/***************************************************************************
 *   Copyright (C) 2008 by Danny Tonidandel   *
 *   danny@labsister01.em.ufop.br   *
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

#include <pvm3.h>

using namespace std;


main()
{
        int ptid;
	int msgtag = 0;
	int info = 0;
        char buf[100];
	

        ptid = pvm_parent(); // Obtem o tid do mestre

        strcpy(buf, "");
        gethostname(buf + strlen(buf), 64);


        pvm_initsend(PvmDataDefault); 
	/* A função pvm_init_send Limpa o buffer "send" e se prepara para compactar uma nova mensagem. O argumento inteiro especifica o esquema de codificação da mensagem.*/
        pvm_pkstr(buf);  // Compacta o buffer para envio
	msgtag = 3;
        pvm_send(ptid, 3);
	/* The routine pvm_send sends a message stored in the active send buffer to the PVM process identified by tid. msgtag is used to label the content of the message. If pvm_send is successful, info will be 0. If some error occurs then info will be < 0.
*/

	
        pvm_exit();
	
	exit(0);
}
