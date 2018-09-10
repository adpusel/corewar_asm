#!/bin/sh

ASM_FILE="vm_champs/okTest100"

echo "Our Assembler:"
./asm $ASM_FILE".s" && hexdump -C $ASM_FILE".mycor" > vm_champs/mycor.hex
echo "Their Assembler:"
./ft_asm $ASM_FILE".s" && hexdump -C $ASM_FILE".cor" > vm_champs/cor.hex
touch $ASM_FILE".diff" && diff vm_champs/mycor.hex vm_champs/cor.hex > $ASM_FILE".diff"
cat $ASM_FILE.diff
