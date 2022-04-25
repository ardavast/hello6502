.segment "CODE"

PORTA = $6001
DDRA  = $6003

reset:
    ; set up stack
    ldx #$ff
    txs

    lda #$7f
    sta DDRA
    lda #$00
    sta PORTA

    lda #$03
    jsr write_4
    jsr write_4
    jsr write_4

    lda #$02
    jsr write_4

    lda #$28
    jsr write_i

    lda #$0c
    jsr write_i

    lda #$01
    jsr write_i

    lda #$06
    jsr write_i

    lda #$48
    jsr write_d
    lda #$65
    jsr write_d
    lda #$6c
    jsr write_d
    lda #$6c
    jsr write_d
    lda #$6f
    jsr write_d
    lda #$2c
    jsr write_d
    lda #$20
    jsr write_d
    lda #$57
    jsr write_d
    lda #$6f
    jsr write_d
    lda #$72
    jsr write_d
    lda #$6c
    jsr write_d
    lda #$64
    jsr write_d
    lda #$21
    jsr write_d

loop:
    nop
    jmp loop

write_4:
    pha ; save A
    txa
    pha ; save X
    tsx
    lda PORTA
    and #$f0
    ora $102, X
    sta PORTA

    ora #$10
    sta PORTA ; clk high

    and #$ef
    sta PORTA ; clk low

    pla
    tax ; restore X
    pla ; restore A
    rts

write_i:
    pha ; save A
    pha
    pha
    lda PORTA
    and #$bf
    sta PORTA
    pla
    lsr
    lsr
    lsr
    lsr
    jsr write_4
    pla
    and #$0f
    jsr write_4
    pla ; restore A
    rts

write_d:
    pha ; save A
    pha
    pha
    lda PORTA
    ora #$40
    sta PORTA
    pla
    lsr
    lsr
    lsr
    lsr
    jsr write_4
    pla
    and #$0f
    jsr write_4
    pla ; restore A
    rts

.segment "VECTORS"
.word reset
.word reset
.word reset
