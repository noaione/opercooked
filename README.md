# opercooked
Tugas Pertama Algorithm Bootcamp Season 2

## Compiling
Cara compile project ini cukup mudah.

1. Ubah direktori ke root directory project ini<br>
    Misalkan situ download/clone di folder `/home/username/opercooked`<br>
    Maka pindah ke direktori `/home/username/opercooked` (`cd /home/username/opercooked`)
2. ketik `tools/compile_travis.sh` di Terminal
3. Folder baru akan dibuat yaitu folder `build`
4. Ketik `build/OperCooked_Linux`

## Test Module
1. Include module situ di `src/main.cpp`
2. Comment `int main()` yang ada dan ganti dengan `int main()` yang situ inginkan
3. Lakukan langkah [Compiling](#compiling)

Jangan commit file `src/main.cpp` karena ini cuma untuk test.

## Guidelines Commit Message
Buatlah commit message sejelas mungkin di-baris pertama, baris pertama merupakan Summary dari perubahan yang situ buat.<br>
Misalkan situ merubah file `src/main.cpp` yang menambah menu Drinks, ketik seperti ini misalnya:<br>
`README: Tambah menu Drinks`

Dan kalau mau menjelaskan lebih panjang apa perubahannya, taruh di line 2 dan seterusnya.

Kalau bisa, Line pertama dibataskan ke 72 karakter maksimal.<br>
Format penulisannya adalah: `FILE_YANG_DIUBAH: Perubahan`<br>
`FILE_YANG_DIUBAH` cukup tulis nama filenya tanpa extensionnya (.cpp/.h)

Kenapa kayak gini? Biar enak diliat.
