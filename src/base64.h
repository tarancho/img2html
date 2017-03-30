/* -*- mode: c++; coding: sjis; -*-
 * Copyright (C) 2005 Tadamegu Furukawa
 * $Id: base64.h,v 1.1 2005/08/03 01:33:47 tfuruka1 Exp $
 * $Name:  $
 *
 * Base64�֘A
 *
 * $Log: base64.h,v $
 * Revision 1.1  2005/08/03 01:33:47  tfuruka1
 * Face�Ή��̑O�����Ƃ���Base64�̃f�R�[�h��ImagiMagic��convert.exe���w��
 * �ł���悤�ɑΉ��B
 *
 */
#ifndef _BASE64_H_
#define _BASE64_H_

#include <stdio.h>
#include <string.h>

/*
 * Base64�ɃG���R�[�h���܂��B�G���R�[�h���ʊi�[��́A���f�[�^�� 4/3 �{
 * �̃G���A���K�v�ɂȂ�܂�(3�o�C�g��4�o�C�g�ɂȂ�܂�)�B�G���R�[�h��
 * �̃f�[�^���͕K����4�̔{���ɂȂ�܂��B�܂��A�Ō��null�X�g�b�v��t�^
 * ���܂��̂ŁA����Ɉ�o�C�g�]���ɕK�v�ɂȂ�܂��B
 */
char *
EncodeBase64(
    unsigned char *lpData,                   // �G���R�[�h�f�[�^
    size_t cbData,                           // �o�C�g��
    char *lpszEncode                         // �G���R�[�h����(������)
    );

/*
 * Base64�Ńf�R�[�h���܂��B�f�R�[�h����錳�̕����񒷂͕K��4�̔{���ł�
 * ��K�v������܂��B�f�R�[�h��̃o�C�g����ԋp���܂��B�f�R�[�h�O�̃G
 * ���A�ƃf�R�[�h��̃G���A�͓����A�h���X���w�肷�鎖���\�ł��B
 */
long
DecodeBase64(
    char *lpszData,                             // �K��4�̔{���ł��鎖
    unsigned char *lpData                       // �f�R�[�h����
    );

/*
 * Base64�ŃG���R�[�h���ꂽ�t�@�C�����f�R�[�h���A�t�@�C���ɏo�͂��܂��B
 * ���̓t�@�C���Əo�̓t�@�C���𓯂��ɂ��鎖�͂ł��܂���B
 */
long
DecodeBase64File(
    char *lpszBase64FileName,                   // ���̓t�@�C����
    char *lpszOutFileName                       // �o�̓t�@�C����
    );

#endif

/*
 * Local Variables:
 * mode: c
 * coding: utf-8-unix
 * End:
 */
