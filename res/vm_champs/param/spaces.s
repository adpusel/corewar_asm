.name "Spaceborg"
.comment "test des espaces dans les parametres"

label1:		sti r112,%:label2,	   	 %1
label2:			ldi%120,%4,r1
				and :label1  ,  120, 		  r1 	  	 	 	

