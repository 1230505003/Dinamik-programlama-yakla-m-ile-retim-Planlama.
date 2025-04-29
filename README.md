# Minimum İşlem Süresi Hesaplama (Dinamik Programlama)

Bu proje, farklı makinelerde belirli işlem sürelerine ve geçiş maliyetlerine sahip birden fazla işin, minimum toplam sürede tamamlanması problemini dinamik programlama (DP) kullanarak çözmektedir.

## 🚀 Amaç

Verilen `n` adet iş ve `m` adet makine için:
- Her işin her makinadaki işlem süresi (`time[n][m]`)
- Makineler arası geçiş maliyetleri (`cost[m][m]`)

Kullanılarak işler sırasıyla işlenir. Amaç, işleri sırasıyla işleyecek şekilde minimum toplam süreyi bulmaktır.

## 🛠️ Kullanılan Teknikler

- **Dinamik Programlama (DP):** `dp[i][j]` ifadesi, `i` numaralı işin `j` numaralı makinada işlenmesi durumundaki minimum toplam süreyi ifade eder.
- **Geçiş Maliyeti Hesaplama:** İşler ardışık olarak yapılırken, makineler arası geçişlerin süresel maliyetleri hesaplamaya dahil edilir.

## 📌 Algoritma Detayları

1. **Giriş Alımı**
   - İş ve makine sayısı kullanıcıdan alınır.
   - İşlem süreleri ve geçiş maliyetleri kullanıcıdan alınır.

2. **Başlangıç Durumu**
   - İlk işin her makinada işlenme süresi `dp[0][j]` olarak kaydedilir.

3. **Geçişlerin Hesaplanması**
   - Her iş için tüm makine seçenekleri değerlendirilir.
   - Önceki işin işlendiği makinadan geçiş maliyeti hesaplanır.
   - Minimum toplam süre seçilir:
     ```c
     dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[k][j] + time[i][j]);
     ```

4. **Sonucun Bulunması**
   - Son iş için tüm makinelerdeki minimum değer bulunarak sonuç yazdırılır.

## 📈 Zaman Karmaşıklığı

- **O(n × m × m)**

## 💡 Örnek Girdi / Çıktı

Her iş için tüm makineler ve önceki makineler üzerinden döngü kurularak hesaplama yapılır.

Is sayisini girin: 4
Makine sayisini girin: 3
Islem surelerini girin (n satir m sutun):
4 6 8
2 5 7
3 4 6
5 2 3
Gecis maliyetlerini girin (m satir m sutun):
0 3 1
2 0 4
1 2 0
Çıktı;
Minimum toplam sure: 21
