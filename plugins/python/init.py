from hexchat import ffi  # , lib


@ffi.def_extern()
def on_pytest(word, word_eol, userdata):
    for i in range(1, 32, 1):
        string = ffi.string(word[i])
        if string == b'':
            break
        print(string.decode())
    return 0
