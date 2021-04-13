segment .text
        global  _restar

_restar:
        enter   0,0             ; make room for sub on stack

        mov     eax, [ebp+8]    ; eax = A
        sub     eax, [ebp+12]   ; eax = eax - B

        leave
        ret