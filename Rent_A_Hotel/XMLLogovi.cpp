
// ******************************************************************************** //
//                                                                                
//                                XML Data Binding                                
//                                                                                
//         Generated on: 20.10.2025. 9:30:07                                      
//       Generated from: C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xml   
//   Settings stored in: C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xdb   
//                                                                                
// ******************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "XMLLogovi.h"


// Global Functions 

_di_IXMLlogoviType __fastcall Getlogovi(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLlogoviType) Doc->GetDocBinding("logovi", __classid(TXMLlogoviType), TargetNamespace);
};

_di_IXMLlogoviType __fastcall Getlogovi(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getlogovi(DocIntf);
};

_di_IXMLlogoviType __fastcall Loadlogovi(const System::UnicodeString& FileName)
{
  return (_di_IXMLlogoviType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("logovi", __classid(TXMLlogoviType), TargetNamespace);
};

_di_IXMLlogoviType __fastcall  Newlogovi()
{
  return (_di_IXMLlogoviType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("logovi", __classid(TXMLlogoviType), TargetNamespace);
};

// TXMLlogoviType 

void __fastcall TXMLlogoviType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("log"), __classid(TXMLlogType));
  ItemTag = "log";
  ItemInterface = __uuidof(IXMLlogType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLlogType __fastcall TXMLlogoviType::Get_log(const int Index)
{
  return (_di_IXMLlogType) List->Nodes[Index];
};

_di_IXMLlogType __fastcall TXMLlogoviType::Add()
{
  return (_di_IXMLlogType) AddItem(-1);
};

_di_IXMLlogType __fastcall TXMLlogoviType::Insert(const int Index)
{
  return (_di_IXMLlogType) AddItem(Index);
};

// TXMLlogType 

System::UnicodeString __fastcall TXMLlogType::Get_datum()
{
  return GetChildNodes()->Nodes[System::UnicodeString("datum")]->Text;
};

void __fastcall TXMLlogType::Set_datum(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("datum")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLlogType::Get_id()
{
  return GetChildNodes()->Nodes[System::UnicodeString("id")]->Text;
};

void __fastcall TXMLlogType::Set_id(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("id")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLlogType::Get_aktivnost()
{
  return GetChildNodes()->Nodes[System::UnicodeString("aktivnost")]->Text;
};

void __fastcall TXMLlogType::Set_aktivnost(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("aktivnost")]->NodeValue = Value;
};

// TXMLlogTypeList 

_di_IXMLlogType __fastcall TXMLlogTypeList::Add()
{
  return (_di_IXMLlogType) AddItem(-1);
};

_di_IXMLlogType __fastcall TXMLlogTypeList::Insert(const int Index)
{
  return (_di_IXMLlogType) AddItem(Index);
};

_di_IXMLlogType __fastcall TXMLlogTypeList::Get_Item(const int Index)
{
  return (_di_IXMLlogType) List->Nodes[Index];
};
