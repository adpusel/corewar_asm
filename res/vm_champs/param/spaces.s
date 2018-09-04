.name "Spaceborg"
.comment "test des espaces dans les parametres"

			sti r1 , 		r2,r3   
label1:		sti r15 , %:label2 ,	   	 %1
label2:			ldi%120,%4,r1
				and :label1  ,  2147483649, 		  r1 	  	 	 	

