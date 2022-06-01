####### C++ project


######## Jak uruchomić program 

Otworzyć Visual Studio oraz sklonować repozytorium z tego linku 
https://github.com/mario343/Cppproject.git

Zbudować oba rozwiązania
Zmienić odpowiednią ścieżkę w kodzie w Myform.h (znajduje się w Header Files) dla Project3
dokładnie 143 linijkę kodu na odpowiednią ścieżkę w której znajduje się plik exe od gry

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Process::Start("D:\\VSTUDIO 2022\\Pongoo\\x64\\Debug\\Pongoo.exe"); 
	}
 \\Pongoo\\x64\\Debug\\Pongoo.exe pozostaje takie samo 
 
Uruchomić programy.



######## Jeśli nie zadziała to:

Zbudować rozwiązanie dla Pongoo
Zbudować rozwiązanie dla Project3 (Okno.sln)

Zmienić odpowiednią ścieżkę w kodzie w Myform.h (znajduje się w Header Files) dla Project3
dokładnie 143 linijkę kodu na odpowiednią ścieżkę w której znajduje się plik exe od gry


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Process::Start("D:\\VSTUDIO 2022\\Pongoo\\x64\\Debug\\Pongoo.exe"); 
	}
 \\Pongoo\\x64\\Debug\\Pongoo.exe pozostaje takie samo 
 
 Uruchomić programy.
 
 
 ################### ################### ################### ################### ###################
 Urochomić programy możemy na 2 sposoby

 1.debugowując je w Visual Studio
 
 2.można też uruchomić je za pomocą plików .exe
 które znajdują się w \\x64\\Debug\\ w każdym z folderów, w którym znajdują się rozwiązania
 
 ## Mariusz Wilk 2022
  
