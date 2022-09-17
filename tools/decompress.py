import lzw
dir(lzw)

compressed = lzw.readbytes('LABS.PIC')

#with open('LABS.PIC') as bfile:
#    compressed = bfile.read()
#print(compressed)
#print(len(compressed))
#print('----')

# decoded = lzw.Decoder(codepoints)
# out = b''.join(decoded)

decompressed = b''.join(lzw.decompress(compressed))

print(decompressed)
