#include "./include/h.hh"
//#define MY_DLL __declspec(dllexport)

int main() {

	//std::filesystem::path mypath:

	
	std::string archivo; 
	archivo = "PS0905JN";
	Muestra myMuestra = Muestra(archivo);
	float prueba;
	prueba = myMuestra.promedioSimple("Fe");
	std::cout << "\n" + std::to_string(prueba) + "\n--------------------><-------------------- \n\n";
	std::cin.get();
	return 0;
}