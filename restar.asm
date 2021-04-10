%include "asm_io.inc"

segment .data
;
; los datos iniciados se colocan en el segmento de
; datos ac ́a
;

segment .bss
;
; Datos no iniciados se colocan en el segmento bss
;
segment .text
global _asm_main
_asm_main:
enter 0,0 ; rutina de
pusha

;
; El c ́odigo est ́a colocado en el segmento de texto. No modifique el
; c ́odigo antes o despu ́es de este comentario ;
popa
mov eax, 0 ; retornar a C
leave
ret