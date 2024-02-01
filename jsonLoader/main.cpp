/*
 *	@File	main.cpp
 *	@Brief	Jsonファイル入出力の実験プロジェクト。
 *	@Date	2023-01-18
 *  @Author NakamuraRyo
 */

#include <iostream>
#include "JsonHelper.h"

int main()
{
	// ファイルの読み込み
	JsonHelper _json;
	std::cout << "ファイルパス:";
	std::wstring _path; std::wcin >> _path;
	_json.Load(_path.c_str());

	// データの取得
	auto _data = _json.GetData();

	// データの操作
	for (int i = 0; i < _data.size(); i++)
	{
		// 表示
		std::cout << _data[i] << std::endl;

		// 編集
		//_data[i]["Position"] = { i * i,i + 10,30 };
		//_data[i]["Rotation"] = { i * (i + 1),0,0 };
	}

	// 書き出し先を変更
	//_json.SetPath(L"JsonApp/output/example.json");

	// データを書き出す
	//std::string _output = _data.dump(2);
	//_json.Write(_output);

	system("pause");
	return EXIT_SUCCESS;
}

/* JsonHelper使用法

　【宣言から取得まで】
　①JsonHelper型で宣言する。

  ②Load関数でJson形式のファイルを読み込む。

  ③GetData関数でJson形式のデータを取得する。
　　例）auto _data = _json.GetData();

  【取得詳細】
  ①データ[インデックス番号]でデータ１行が取得可能。
  　例）std::cout << _data[0];　配列番号0番の全要素を表示。

  ②データ[インデックス番号][パラメータ名(string型)]で各項目のパラメータを取得可能。
  　例）std::cout << _data[0]["Name"];　配列番号0番の「Name」パラメータの内容を表示。
　　補足：Vector3等子の要素がある場合は、["Position"]["X"]と指定することで取得可能。

  【編集から出力まで】
  ①取得したJsonの配列の直接書き込む。
  例）_json[0]["Name"] = "Cloud";

  ②編集したJsonデータをダンプして文字列に格納する。
  例）_data.dump(2); dumpはインデントを作る。2にすると段落ごとに半角2の空白ができる。

  ③Write関数に②で作った文字列を格納する。
  ※書き出し先は最後に開いたJsonファイルに書き出される。
*/