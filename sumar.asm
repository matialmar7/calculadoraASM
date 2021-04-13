segment .text
        global  _sumar

_sumar:
        enter   0,0              ; hace push e inicializa el registro ebp ->   1) push -> ebp  2) ebp <- esp

        mov     eax, [ebp+8]      ; eax = A             ebp+8 posicion en el stack de A
        add     eax, [ebp+12]     ; eax = eax + B       ebp+12 pisicion en el stack de B

        leave                   ;opuesto a enter- 1)ebp->esp y 2)pop ebp
        ret