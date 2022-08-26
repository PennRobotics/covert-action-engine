sox -V -r 48000 -n --comment "" -b 16 -c 2 test.wav synth 2 sin 256 sin 300+384 remix 1,2 vol -10dB
