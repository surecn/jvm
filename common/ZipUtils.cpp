//
// Created by 郑邦国 on 2018/12/24.
//

#include "ZipUtils.h"

#define WRITEBUFFERSIZE (1242880) // 5Mb buffer

string ZipUtils::readZipFile(string zipFile, string fileInZip) {
    int err = UNZ_OK;                 // error status
    uInt size_buf = WRITEBUFFERSIZE;  // byte size of buffer to store raw csv data
    void* buf;                        // the buffer
    string sout;                      // output strings
    char filename_inzip[256];         // for unzGetCurrentFileInfo
    unz_file_info file_info;          // for unzGetCurrentFileInfo

    unzFile uf = unzOpen64(zipFile.c_str()); // open zipfile stream
    if (uf == NULL) {
        cerr << "Cannot open " << zipFile << endl;
        return sout;
    } // file is open


    if ( unzLocateFile(uf,fileInZip.c_str(),1) ) { // try to locate file inside zip
        // second argument of unzLocateFile: 1 = case sensitive, 0 = case-insensitive
        cerr << "File " << fileInZip << " not found in " << zipFile << endl;
        return sout;
    } // file inside zip found

    if (unzGetCurrentFileInfo(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0)) {
        cerr << "Error " << err << " with zipfile " << zipFile << " in unzGetCurrentFileInfo." << endl;
        return sout;
    } // obtained the necessary details about file inside zip

    buf = (void*)malloc(size_buf); // setup buffer
    if (buf==NULL) {
        cerr << "Error allocating memory for read buffer" << endl;
        return sout;
    } // buffer ready

    err = unzOpenCurrentFilePassword(uf,NULL); // Open the file inside the zip (password = NULL)
    if (err!=UNZ_OK) {
        cerr << "Error " << err << " with zipfile " << zipFile << " in unzOpenCurrentFilePassword." << endl;
        return sout;
    } // file inside the zip is open

    // Copy contents of the file inside the zip to the buffer
    cout << "Extracting: " << filename_inzip << " from " << zipFile << endl;
    do {
        err = unzReadCurrentFile(uf,buf,size_buf);
        if (err<0) {
            cerr << "Error " << err << " with zipfile " << zipFile << " in unzReadCurrentFile" << endl;
            sout = ""; // empty output string
            break;
        }
        // copy the buffer to a string
        if (err>0) for (int i = 0; i < (int) err; i++) sout.push_back( *(((char*)buf)+i) );
    } while (err>0);

    err = unzCloseCurrentFile (uf);  // close the zipfile
    if (err!=UNZ_OK) {
        cerr << "Error " << err << " with zipfile " << zipFile << " in unzCloseCurrentFile" << endl;
        sout = ""; // empty output string
    }
    unzClose(uf);
    free(buf); // free up buffer memory
    return sout;
}

void ZipUtils::getZipList(string zipFile, std::vector<string> *_vector) {
    char filename_inzip[256];         // for unzGetCurrentFileInfo
    unz_file_info64 file_info;          // for unzGetCurrentFileInfo

    unzFile uf = unzOpen64(zipFile.c_str()); // open zipfile stream
    if (uf == NULL) {
        cout << "Cannot open " << zipFile << endl;
        return;
    }

    int ret = unzGoToFirstFile(uf);
    while (ret == UNZ_OK) {
        ret = unzGetCurrentFileInfo64(uf, &file_info, filename_inzip, sizeof(filename_inzip), NULL, 0L, NULL, 0L);
        if (ret != UNZ_OK) {
            return;
        }
        _vector->push_back(string(filename_inzip));
        ret = unzGoToNextFile(uf);
    }

    unzClose(uf);
}