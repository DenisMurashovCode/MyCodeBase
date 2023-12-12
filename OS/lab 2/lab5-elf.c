#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
const char* elfFile = "list.so";
Elf64_Ehdr header;
Elf64_Shdr sheader;
Elf64_Shdr symtab;
Elf64_Shdr strtab;
Elf64_Sym sym;
char sname[32];
int i;
FILE* file = fopen(elfFile, "rb");
fread(&header, sizeof(header), 1, file);
fseek(file, header.e_shoff, SEEK_SET);
fread(&sheader, sizeof(sheader), 1, file);

for (i=0; i<header.e_shnum; i++){
fseek(file,header.e_shoff+header.e_shentsize*i, SEEK_SET);
fread(&sheader, sizeof(sheader),1,file);
if(i == 4) symtab = (Elf64_Shdr)sheader;
if(i == 5) strtab = (Elf64_Shdr)sheader;
}

for (i=0; i<symtab.sh_size/symtab.sh_entsize;i++){
fseek(file, symtab.sh_offset + symtab.sh_entsize*i, SEEK_SET);
fread(&sym, sizeof(Elf64_Sym),1,file);
fseek(file, strtab.sh_offset+sym.st_name, SEEK_SET);
fread(sname,1,32,file);
if (sym.st_size > 0){
fprintf(stdout, "%d\t%lld\t%u\t%u\t%hd\t%s\n",i,
sym.st_size,
ELF64_ST_TYPE(sym.st_info),
ELF64_ST_BIND(sym.st_info),
sym.st_shndx,sname);
}

}

fseek(file, header.e_shoff + header.e_shstrndx * header.e_shentsize, SEEK_SET);
fread(&sheader, sizeof(sheader), 1, file);
fseek(file, sheader.sh_offset, SEEK_SET);
char sectionNames[sheader.sh_size];
fread(sectionNames, 1, sheader.sh_size, file);

printf("\nSection Names:\n");
for (i = 0; i < header.e_shnum; i++) {
fseek(file, header.e_shoff + i * header.e_shentsize, SEEK_SET);
fread(&sheader, sizeof(sheader), 1, file);
printf("%d\t%s\n", i, &sectionNames[sheader.sh_name]);
}
}
