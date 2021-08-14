#include <iostream>

using namespace std;
void dependence(){
	system("sudo apt-get install mpd ncmpcpp light libxcb-xinerama0-dev libxcb-icccm4-dev libxcb-randr0-dev libxcb-util0-dev libxcb-ewmh-dev libxcb-keysyms1-dev libxcb-shape0-dev compton feh terminator rofi build-essential git cmake cmake-data pkg-config python3-sphinx python3-packaging libcairo2-dev libxcb1-dev libxcb-util0-dev libxcb-randr0-dev libxcb-composite0-dev python3-xcbgen xcb-proto libxcb-image0-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-xkb-dev libxcb-xrm-dev libxcb-cursor-dev libasound2-dev libpulse-dev i3-wm libjsoncpp-dev libmpdclient-dev libcurl4-openssl-dev libnl-genl-3-dev -y");
}

void bspwm_install(){
	system("mkdir bspwm-install && cd bspwm-install && git clone https://github.com/baskerville/bspwm.git && git clone https://github.com/baskerville/sxhkd.git && cd bspwm && sudo make && sudo make install && cd ../sxhkd && sudo make && make install");
	system("sudo cp bspwm-install/bspwm/contrib/freedesktop/bspwm.desktop /usr/share/xsessions/");
}

void config(){
	int a;
	system("mkdir -p ~/.config/{bspwm,sxhkd}");
	system("cp -r doc/bspwm ~/.config/ && cp doc/sxhkd/sxhkdrc ~/.config/sxhkd/ && cp doc/.xinitrc ~/ && cp -r doc/rofi ~/.config/ && cp doc/.Xresources ~/");
	system("chmod u+x ~/.config/bspwm/bspwmrc && chmod +x ~/.config/bspwm/scripts/bspwm_resize && xrdb -load ${HOME}/.Xresources");
	system("cp -r doc/compton ~/.config/");
	system("chmod +x ~/.config/polybar/launch.sh ~/.config/bspwm/.mensaje");
	system("mv {doc/.mpd/,doc/.ncmpcpp/} ~/.config/");
	cout<<"Su procesador es:\n\t1)intel\n\t2)amd\n";
	cin>>a;
	if(a==1){
		system("cp -rf doc/conf/intel/hack ~/.config/polybar/");
	}else{
		system("cp -rf doc/conf/amd/hack ~/.config/polybar/");
	}


}

void polybar(){
	system("chmod +x doc/.install");
	system("cp -r doc/polybar-themes ~/");
	system("sudo ./doc/.install");
	}

void install_config(){
	string selec;
	cout<<"\t\t  ---INSTALACION DE DEPENCIAS---\n";
	cout<<"\tSe empezara a instalar las dependencias necesarias\n\tpara el funcionamiento del entorno de escritorio.\n";
	cout<<"\tLea y siga las ordenes para tener una instalacion\n\t\t\t    exitosa.\n";
	dependence();
	cout<<"\tSe logro instalar todas las dependencias correctamente? (y/n)\n";
	cin>>selec;
	if(selec=="y"){
		system("clear");
		cout<<"\t\t---INSTALACION DE BSPWM---\n";
		cout<<"\tSe empezara a construir el programa\n";
		bspwm_install();
		cout<<"\tSe construyo correctamente? (y/n)\n";
		cin>>selec;
		if(selec=="y"){
			system("clear");
			cout<<"\t\t---INSTALACION DE POLYBAR---\n";
			cout<<"\tSe empezara a construir el programa\n";
			polybar();
			cout<<"Se construyo correctamente? (y/n)\n";
			cin>>selec;
			if(selec=="y"){
				system("clear");
				cout<<"\t\t---CONFIGURACION---\n";
				config();
			}else cout<<"revise si las dependencias se instalaron correctamente\n";
		}else cout<<"revise que las dependencias se instalaron correctamente\n";
	}else cout<<"trate de instalar las dependencias faltantes manualmente\n";
}

int main(){
	string seleccion;
	cout<<"\t\t---AUTO--BSPWM----\n";
	cout<<"\t\t     by Metallica\n";
	cout<<"Este es un instalador de bspwm y configuracion automatizada\n";
	cout<<"Antes del usar este programa actualice sus repositorios y\n";
	cout<<"ejecute este programa la primera ver con sudo ya que para la instalacion se\n";
	cout<<"        necesita permisos de superusuario, la segunda vez ya no lo ejecute con sudo.\n";
	cout<<"---------------------EMPEZAR INSTALACION---- ----------------\n";
	cout<<"-----------------------------(y/n)---------------------------\n";
	cin>>seleccion;
	if(seleccion=="y"){
		install_config();
	}
	cout<<"\t\tBy::Metallica"<<endl;
	return 0;
}
