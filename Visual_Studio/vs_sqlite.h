#pragma once
#ifdef __cplusplus_cli
#include <msclr\marshal_cppstd.h>
//#include "../include/pkmds/stdafx.h"
using namespace System;
using namespace System::Data;
using namespace System::Data::SQLite;
using namespace msclr::interop;
public ref class VS_SQLite
{
public : SQLiteConnection ^db;
public : SQLiteConnection ^imgdb;

		 SQLiteCommand ^cmdSelect;
		 SQLiteDataReader ^reader;

public:  VS_SQLite()
		{
			db = gcnew SQLiteConnection();
			imgdb = gcnew SQLiteConnection();
			String ^ dbdir = "";
#ifdef _DEBUG
			dbdir = "C:\\Users\\Mike\\Documents\\GitHub\\PKMDS-G5\\SQLite Databases\\"; // Laptop
			//dbdir = "C:\\Users\\Michael Bond\\Documents\\GitHub\\PKMDS-G5\\SQLite Databases\\"; // Desktop
			//dbdir = "C:\\Users\\michaelbond\\Documents\\GitHub\\PKMDS-G5\\SQLite Databases\\"; // Work
#endif
			db->ConnectionString = L"Data Source='" + dbdir + L"veekun-pokedex.sqlite'";
			db->Open();
			imgdb->ConnectionString = L"Data Source='" + dbdir + L"images.sqlite'";
			imgdb->Open();
		}
		~VS_SQLite()
		{
			db->Close();
			imgdb->Close();
			delete db;
			delete imgdb;
			delete cmdSelect;
			delete reader;
		}
public:  String ^ getSQLText(String ^ SQL)
		{
			try
			{
				cmdSelect = db->CreateCommand();
				cmdSelect->CommandText = SQL;
				reader = cmdSelect->ExecuteReader();
				reader->Read();
				return reader->GetString(0);
			}
			catch(...)
			{
				return "";
			}
		}
public:  DataSet ^ getSQLDS(String ^ SQL)
		{
			DataSet ^ DS = gcnew DataSet();
			SQLiteDataAdapter ^ DB = gcnew SQLiteDataAdapter(SQL,db);
			DS->Reset();
			DB->Fill(DS);
			delete DB;
			return DS;
		}
public:  DataSet ^ getSQLIMGDS(String ^ SQL)
		{
			DataSet ^ DS = gcnew DataSet();
			SQLiteDataAdapter ^ DB = gcnew SQLiteDataAdapter(SQL,imgdb);
			DS->Reset();
			DB->Fill(DS);
			delete DB;
			return DS;
		}
public:  int getSQLInt(String ^ SQL)
		{
			try
			{
				cmdSelect = db->CreateCommand();
				cmdSelect->CommandText = SQL;
				reader = cmdSelect->ExecuteReader();
				reader->Read();
				return reader->GetInt32(0);
			}
			catch (...)
			{
				return 0;
			}
		}
public:  Drawing::Image^ getSQLImage(String^ SQL)
		{
			SQLiteCommand ^ cmd = imgdb->CreateCommand();
			cmd->CommandText = SQL;
			Object ^ obj = gcnew Object;
			try
			{
				obj = cmd->ExecuteScalar();
			}
			catch(...)
			{

			}
			Drawing::Image ^ img;
			img = nullptr;
			try {
				// http://www.digitalcoding.com/Code-Snippets/CPP-CLI/C-CLI-Code-Snippet-Get-Image-from-sql-server.html
				array<Byte> ^_ImageData = gcnew array<Byte>(0);
				_ImageData = safe_cast<array<Byte>^>(obj);
				IO::MemoryStream ^_MemoryStream = gcnew IO::MemoryStream(_ImageData);
				img = Drawing::Image::FromStream(_MemoryStream);
				delete cmd;
				delete obj;
				delete _ImageData;
				return img;
			}
			catch(...)
			{

			}
			return img;
		}
public:  String ^ getSQLText(std::string sql)
		{
			try
			{
				String^ SQL = gcnew String(sql.c_str());
				return getSQLText(SQL);
			}
			catch(...)
			{
				return "";
			}
		}
public:  std::string getSQLTextstd(std::string sql)
		{
			String^ SQL = gcnew String(sql.c_str());
			String^ sysstring = getSQLText(SQL);
			delete SQL;
			return marshal_as<std::string>(sysstring);
		}
public:  int getSQLInt(std::string sql)
		{
			String^ SQL = gcnew String(sql.c_str());
			return getSQLInt(SQL);
		}
public:  DataSet ^ getSQLDS(std::string sql)
		{
			String^ SQL = gcnew String(sql.c_str());
			return getSQLDS(SQL);
		}
public:  Drawing::Image^ getSQLImage(std::string sql)
		{
			String^ SQL = gcnew String(sql.c_str());
			return getSQLImage(SQL);
		}
};
#endif
