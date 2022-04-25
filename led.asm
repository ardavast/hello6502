.segment "CODE"
reset:
    lda #$ff
    sta $6003
l0:
    lda #$55
    sta $6001
    jmp l1
l1:
    lda #$aa
    sta $6001
    jmp l0

.segment "VECTORS"
.word reset
.word reset
.word reset
