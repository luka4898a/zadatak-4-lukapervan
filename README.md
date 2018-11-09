# Strukture podataka #

### Preduvjeti ###
- Git - https://git-scm.com/downloads
- Visual Studio 2017

### Upute za instalaciju ###

1. Odabrati direktorij gdje ćete spremiti sve vježbe
2. Postaviti korisničko ime i email
```
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
3. Klonirati remote repozirotij na svoje računalo
```
git clone https://github.com/Strukture-podataka/sp-vjezbe-{vaše-git-korisničko-ime}.git
cd sp-vjezbe-{vaše-git-korisničko-ime}
```
4. Inicijalizirali lokalni git repostorijum
```
git init
```
4. Dodati udaljeni git repositorijum
```
git remote add strukture https://github.com/Strukture-podataka/sp-vjezbe-{vaše-git-korisničko-ime}.git
```
5. Otvoriti SP-Vjezbe.sln i uraditi Zadaću.

### Slanje zadaće na Vaš udaljeni repositorijum
1. Provjeriti promjene s naredbom git status
```
git status
```
Rezultti bi trebao biti kao na slici

![alt text](https://raw.githubusercontent.com/fsr-sp/sp-vjezbe/master/images/git_status.png)

2. Spremiti sve datoteke na kojima ste napravili izmjene u Index
```
git add SP-Vjezbe/Datum/Datum.cpp
git add SP-Vjezbe/DvodimenzionalnoPolje/DvodimenzionalnoPolje.cpp
git add SP-Vjezbe/Pokazivaci/Pokazivaci.cpp
```
3. Nakon što smo dodali datoteke spremi smo za commit. Git status bi trebao izgledati ovako:

![alt text](https://raw.githubusercontent.com/fsr-sp/sp-vjezbe/master/images/git_added.png)

4. Spremiti izmjene
```
git commit -m "Ovdje napisti ime commit-a"
```

5. Slanje lokalnih promjena na vaš udaljeni repozitorij

```
git push
```

### SP-Vježbe ###

* Pokazivači - 30.10.2018.
* Dinamička alokacija memorije, datoteke - 6.10.2018.

