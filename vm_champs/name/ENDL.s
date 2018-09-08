.name			"ENDL
blip
blop
bloup
borg"		 
.comment		"le nom peut contenir des \n"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
