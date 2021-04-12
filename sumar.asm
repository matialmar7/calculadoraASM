segment .text
        global  sumar

sumar:
        enter   0,0              ; make room for sum on stack

        mov     eax, [ebp+8]      ; eax = A
        add     eax, [ebp+12]     ; eax = eax + B

        leave
        ret