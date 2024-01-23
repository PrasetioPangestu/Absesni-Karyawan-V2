#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk menambahkan karyawan
void tambahkanKaryawan(vector<string> &daftarKaryawan) {
    string nama;
    cout << "Masukkan nama karyawan: ";
    cin >> nama;
    daftarKaryawan.push_back(nama);
    cout << "Karyawan ditambahkan" << endl;
}

// Fungsi untuk menghapus karyawan
void hapusKaryawan(vector<string> &daftarKaryawan) {
    string nama;
    cout << "Masukkan nama karyawan: ";
    cin >> nama;

    auto it = find(daftarKaryawan.begin(), daftarKaryawan.end(), nama);
    if (it != daftarKaryawan.end()) {
        daftarKaryawan.erase(it);
        cout << "Karyawan dihapus" << endl;
    } else {
        cout << "Karyawan tidak ditemukan" << endl;
    }
}

// Fungsi untuk menampilkan daftar karyawan
void daftarKaryawanMenu(const vector<string> &daftarKaryawan) {
    cout << setw(15) << "Nama Karyawan" << endl;
    for (const string &nama : daftarKaryawan) {
        cout << setw(15) << nama << endl;
    }
}

// Fungsi untuk absensi
void absensiMenu(const vector<string> &daftarKaryawan) {
    string nama;
    cout << "Masukkan nama anda: ";
    cin >> nama;

    auto it = find(daftarKaryawan.begin(), daftarKaryawan.end(), nama);
    if (it != daftarKaryawan.end()) {
        cout << "Valid" << endl;

        int jamAbsensi;
        cout << "Jam Absensi (minimal 9): ";
        cin >> jamAbsensi;

        if (jamAbsensi >= 9 && jamAbsensi < 17) {
            cout << "Shift Kerja: Pagi" << endl;
        } else if (jamAbsensi >= 17 && jamAbsensi <= 24) {
            cout << "Shift Kerja: Malam" << endl;
        } else {
            cout << "Waktu absensi tidak valid." << endl;
        }
    } else {
        cout << "Tidak Valid. Nama tidak terdaftar." << endl;
    }
}


int main() {
    vector<string> daftarKaryawan;
    string passcode;

    while (true) {
        cout << "===== Selamat Datang =====" << endl;
        cout << "1. Akses Fitur Admin" << endl;
        cout << "2. Akses Fitur Karyawan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih akses (0 untuk keluar): ";
        cin >> passcode;

        if (passcode == "0") {
            break;
        } else if (passcode == "1111") { // Admin
            while (true) {
                cout << "===== Fitur Admin =====" << endl;
                cout << "1. Tambahkan Karyawan" << endl;
                cout << "2. Hapus Karyawan" << endl;
                cout << "3. Daftar Karyawan" << endl;
                cout << "4. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu (0 untuk kembali): ";
                cin >> passcode;

                if (passcode == "0") {
                    break;
                } else if (passcode == "1") {
                    tambahkanKaryawan(daftarKaryawan);
                } else if (passcode == "2") {
                    hapusKaryawan(daftarKaryawan);
                } else if (passcode == "3") {
                    daftarKaryawanMenu(daftarKaryawan);
                }
            }
        } else if (passcode == "2222") { // Karyawan
            while (true) {
                cout << "===== Fitur Karyawan =====" << endl;
                cout << "1. Absensi" << endl;
                cout << "2. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu (0 untuk kembali): ";
                cin >> passcode;

                if (passcode == "0") {
                    break;
                } else if (passcode == "1") {
                    absensiMenu(daftarKaryawan);
                }
            }
        } else {
            cout << "Passcode salah. Coba lagi." << endl;
        }
    }

    cout << "Terima kasih. Program selesai." << endl;
    
    return 0;
}
