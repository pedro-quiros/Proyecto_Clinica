#ifndef ARCHIVOCLASSPACIENTESS_H_INCLUDED
#define ARCHIVOCLASSPACIENTESS_H_INCLUDED


class ArchivoPaciente{
private:
    char nombre[30];
public:
    ArchivoPaciente(const char *n){
        strcpy(nombre, n);
    }
    Paciente leerRegistro(int pos){
        Paciente reg;
        //reg.setCategoria(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Paciente);
    }
    bool grabarRegistro(Paciente reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};






#endif // ARCHIVOCLASSPACIENTESS_H_INCLUDED
