MEMORY {
    PRG:      start = $8000, size = $8000, type = ro, file = %O, fill = yes, fillval = $00;
}

SEGMENTS {
    CODE:     load = PRG, type = ro;
    VECTORS:  load = PRG, type = ro, start = $FFFA;
}
