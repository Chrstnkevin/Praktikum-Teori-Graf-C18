# Praktikum-Teori-Graf

| Nama           | NRP            |
| ---------------| ---------------|
| Abdullah Yasykur Bifadhlil Midror      | 5025211035      |
| Duevano Fairuz Pandya     | 5025211052      |
| Christian Kevin Emor     | 5025211153      |

# PPT 2
ini soal

# PPT 3

> Jika sebuah bidak kuda diletakkan pada sebarang kotak untuk kemudian melakukan perjalanan (dengan cara pergerakan kuda) mengunjungi ke semua (8 x 8) kotak papan catur.
> Jika diinginkan situasi bahwa kuda tsb dapat:
> Jika sebuah bidak kuda diletakkan pada sebarang kotak untuk kemudian melakukan perjalanan (dengan cara pergerakan kuda) mengunjungi ke semua (8 x 8) kotak papan catur.
> Jika diinginkan situasi bahwa kuda tsb dapat:
> - Mengakhiri perjalanan pada attacking square (closed tour);
> - Mengakhiri perjalanan di sebarang kotak (open tour);
> Maka aplikasikan algoritma untuk menyelesaikan masalah di atas ke dalam sebuah program dengan menunjukkan rute perjalanan seperti gambar kanan bawah.
> 
> ![image](https://github.com/Chrstnkevin/Praktikum-Teori-Graf-C18/assets/97864068/c9f2d65e-9d84-444d-a69f-8108a3de71a5)


### - Mengakhiri perjalanan pada attacking square (closed tour)

Algoritma backtracking adalah algoritma pencarian yang digunakan untuk memecahkan masalah yang dapat direpresentasikan sebagai pohon keputusan. Algoritma ini bekerja dengan cara mengeksplorasi semua kemungkinan cabang di pohon keputusan hingga menemukan solusi yang valid. Pada masalah perjalanan kuda, pohon keputusan dapat direpresentasikan sebagai berikut:
> - Akar: Posisi kuda awal
> - Cabang: Langkah kuda berikutnya
> - Daun: Posisi kuda yang telah mengunjungi semua kotak di papan catur
Algoritma backtracking akan mengeksplorasi semua kemungkinan langkah kuda hingga menemukan daun yang valid. Jika tidak ada daun yang valid, maka algoritma akan gagal.

Heuristik Warnsdorff adalah heuristik yang digunakan untuk memprediksi langkah kuda berikutnya yang paling mungkin menghasilkan solusi closed tour. Heuristik ini bekerja dengan cara menghitung jumlah tetangga kosong yang belum dikunjungi dari setiap posisi kuda. Pada masalah perjalanan kuda, heuristik Warnsdorff dapat digunakan untuk mengoptimalkan algoritma backtracking sebagai berikut:
> - Langkah pertama kuda: Kuda selalu bergerak ke arah yang memiliki jumlah tetangga kosong paling sedikit.
> - Langkah berikutnya: Kuda akan mencoba ke arah yang memiliki jumlah tetangga kosong paling sedikit, kecuali jika arah tersebut sudah pernah dikunjungi.
> - Jika semua arah sudah pernah dikunjungi, kuda akan mencoba ke arah yang memiliki jumlah tetangga kosong paling sedikit.
Dengan menggunakan heuristik Warnsdorff, algoritma backtracking dapat menemukan solusi closed tour lebih cepat.

Lalu bagaimana algoritma backtracking dengan optimasi menggunakan heuristik Warnsdorff dapat menyelesaikan persoalan perjalanan kuda dengan closed tour?
1. Algoritma dimulai dengan mengeksplorasi cabang yang mewakili langkah kuda pertama.
2. Jika cabang ini tidak menghasilkan solusi closed tour, maka algoritma akan mengeksplorasi cabang berikutnya.
3. Algoritma akan terus mengeksplorasi cabang-cabang berikutnya hingga menemukan cabang yang menghasilkan solusi closed tour.
4. Heuristik Warnsdorff digunakan untuk mengoptimalkan algoritma backtracking dengan cara memprediksi langkah kuda berikutnya yang paling mungkin menghasilkan solusi closed tour. Dengan menggunakan heuristik Warnsdorff, algoritma backtracking dapat menemukan solusi closed tour lebih cepat.

untuk struktur dari codingan berikut adalah penjelasan singkat dari codingan kami:
- Kelas CurrentTile: Digunakan untuk menyimpan posisi (x, y) kuda saat ini.
- N = 8: Ukuran papan catur (8x8).
- Variabel moves_x dan moves_y: Mendefinisikan 8 kemungkinan arah gerakan kuda.
- Fungsi isLegal: Mengecek apakah posisi kandidat berada di dalam papan catur.
- Fungsi isempty: Mengecek apakah posisi kandidat kosong (belum dikunjungi).
- Fungsi getDegree: Menghitung jumlah tetangga kosong yang belum dikunjungi (menggunakan heuristik Warnsdorff).
- Fungsi nextMove: Mencari langkah selanjutnya dengan prioritas ke arah yang memiliki minimal tetangga kosong dan masih legal (menggunakan heuristik Warnsdorff).
- Fungsi print_tour: Menampilkan rute perjalanan kuda pada papan catur.
- Fungsi neighbour: Mengecek apakah posisi kandidat adalah tetangga dari titik awal.
- Fungsi findClosedTour: Menjalankan proses pencarian rute dengan backtracking dan heuristik Warnsdorff, mengembalikan True jika solusi ditemukan dan False jika tidak.
- Looping utama: Mencari solusi berulang kali hingga ditemukan rute closed tour yang valid.

Saat initial position kita definisikan sebagai start_x = 7 dan start_y = 7 mendefinisikan bahwa kuda akan berada di posisi pojok kanan bawah dan didapatkan output sebagai berikut
![image](https://github.com/Chrstnkevin/Praktikum-Teori-Graf-C18/assets/97864068/3fd2f82b-5a49-4c64-acd3-f6dd3a9e2a95)

kuda akan berada di posisi (7,7) dimana diwakili angka 1 dan akan terus bergerak hingga di posisi terakhir yaitu 64 yang merupakan posisi terakhir dari papan catur 8x8

![image](https://github.com/Chrstnkevin/Praktikum-Teori-Graf-C18/assets/97864068/523a3c58-2929-4399-a615-5befe03974d4)

### - Mengakhiri perjalanan di sebarang kotak (open tour)

Algoritma backtracking bekerja secara inkremental untuk menyelesaikan masalah. Biasanya, kita memulai dengan vektor solusi kosong dan satu per satu menambahkan elemen (artinya elemen ini bervariasi tergantung pada masalah yang dihadapi. Dalam konteks masalah tour Knight, elemen ini adalah langkah dari Knight). 

Ketika kita menambahkan elemen, kita memeriksa apakah penambahan elemen saat ini melanggar batasan masalah; jika ya, kita menghapus elemen tersebut dan mencoba alternatif lain. Jika tidak ada alternatif yang berhasil, kita kembali ke tahap sebelumnya dan menghapus elemen yang ditambahkan pada tahap sebelumnya. Jika kita kembali ke tahap awal, kita menyatakan bahwa tidak ada solusi yang ada. Jika penambahan elemen tidak melanggar batasan, kita secara rekursif menambahkan elemen satu per satu. Jika vektor solusi menjadi lengkap, kita mencetak solusi tersebut.

Berikut adalah algoritma backtracking untuk masalah tour Knight:
```
If semua kotak sudah dikunjungi,
    cetak solusinya.
Else,
   a) Tambahkan salah satu langkah berikutnya ke vektor solusi dan secara rekursif
   periksa apakah langkah ini mengarah ke solusi. (Sebuah Knight dapat membuat maksimum
   delapan langkah. Kami memilih salah satu dari 8 langkah pada langkah ini).
   b) Jika langkah yang dipilih pada langkah sebelumnya tidak mengarah ke solusi,
   maka hapus langkah ini dari vektor solusi dan coba alternatif lain.
   c) Jika tidak ada alternatif yang berhasil, kembalikan false (Mengembalikan false
   akan menghapus item yang ditambahkan sebelumnya dalam rekursi dan jika false
   dikembalikan oleh panggilan rekursi awal, maka "tidak ada solusi yang ada").
```
Berikut penjelasan singkat struktur kodingan dari kelompok kami.
- Fungsi `isSafe()` adalah fungsi bantu yang memeriksa apakah posisi yang diberikan `(x, y)` di papan catur adalah langkah yang valid untuk kuda. Fungsi ini mengembalikan `True` jika langkahnya valid, dan `False` sebaliknya.
- Fungsi `printSolution()` adalah fungsi bantu untuk mencetak matriks papan catur.
- Fungsi `solveKT()` adalah fungsi utama yang menginisialisasi papan catur, mendefinisikan kemungkinan langkah kuda, dan memanggil fungsi bantu `solveKTUtil()` untuk memecahkan masalah Tur Kuda.
- Fungsi `solveKTUtil()` adalah fungsi bantu rekursif yang mencoba untuk menemukan solusi untuk masalah Tur Kuda menggunakan backtracking. Fungsi ini mencoba semua langkah yang mungkin dan secara rekursif menjelajahi ruang solusi.
- Terakhir, kode pengendali mengambil input untuk ukuran papan catur (`n`) dan memanggil fungsi `solveKT()` untuk menemukan dan mencetak solusi Tur Kuda.

Berikut adalah rute kuda pada papan catur yang dihasilkan dari kode tersebut
![image](3b.jpg)
