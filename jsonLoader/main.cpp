/*
 *	@File	main.cpp
 *	@Brief	Json�t�@�C�����o�͂̎����v���W�F�N�g�B
 *	@Date	2023-01-18
 *  @Author NakamuraRyo
 */

#include <iostream>
#include "JsonHelper.h"

int main()
{
	// �t�@�C���̓ǂݍ���
	JsonHelper _json;
	std::cout << "�t�@�C���p�X:";
	std::wstring _path; std::wcin >> _path;
	_json.Load(_path.c_str());

	// �f�[�^�̎擾
	auto _data = _json.GetData();

	// �f�[�^�̑���
	for (int i = 0; i < _data.size(); i++)
	{
		// �\��
		std::cout << _data[i] << std::endl;

		// �ҏW
		//_data[i]["Position"] = { i * i,i + 10,30 };
		//_data[i]["Rotation"] = { i * (i + 1),0,0 };
	}

	// �����o�����ύX
	//_json.SetPath(L"JsonApp/output/example.json");

	// �f�[�^�������o��
	//std::string _output = _data.dump(2);
	//_json.Write(_output);

	system("pause");
	return EXIT_SUCCESS;
}

/* JsonHelper�g�p�@

�@�y�錾����擾�܂Łz
�@�@JsonHelper�^�Ő錾����B

  �ALoad�֐���Json�`���̃t�@�C����ǂݍ��ށB

  �BGetData�֐���Json�`���̃f�[�^���擾����B
�@�@��jauto _data = _json.GetData();

  �y�擾�ڍׁz
  �@�f�[�^[�C���f�b�N�X�ԍ�]�Ńf�[�^�P�s���擾�\�B
  �@��jstd::cout << _data[0];�@�z��ԍ�0�Ԃ̑S�v�f��\���B

  �A�f�[�^[�C���f�b�N�X�ԍ�][�p�����[�^��(string�^)]�Ŋe���ڂ̃p�����[�^���擾�\�B
  �@��jstd::cout << _data[0]["Name"];�@�z��ԍ�0�Ԃ́uName�v�p�����[�^�̓��e��\���B
�@�@�⑫�FVector3���q�̗v�f������ꍇ�́A["Position"]["X"]�Ǝw�肷�邱�ƂŎ擾�\�B

  �y�ҏW����o�͂܂Łz
  �@�擾����Json�̔z��̒��ڏ������ށB
  ��j_json[0]["Name"] = "Cloud";

  �A�ҏW����Json�f�[�^���_���v���ĕ�����Ɋi�[����B
  ��j_data.dump(2); dump�̓C���f���g�����B2�ɂ���ƒi�����Ƃɔ��p2�̋󔒂��ł���B

  �BWrite�֐��ɇA�ō������������i�[����B
  �������o����͍Ō�ɊJ����Json�t�@�C���ɏ����o�����B
*/