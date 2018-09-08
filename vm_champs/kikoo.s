#qwfqwefqweffwcc
.name "zork"
.comment "I'M ALIIIIVE" #cccccc

l2:   #comment label

		sti r1, %:live, %1 #dqdqd
		and r1, %0, r1

live:	live %1
		zjmp %:live
