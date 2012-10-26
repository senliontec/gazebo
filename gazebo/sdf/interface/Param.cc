/*
 * Copyright 2011 Nate Koenig
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/* Desc: Parameter class
 * Author: Nate Koenig
 * Date: 14 Aug 2008
 */

#include "common/Exception.hh"
#include "sdf/interface/Param.hh"

using namespace sdf;

std::vector<Param*> *Param::params = NULL;

//////////////////////////////////////////////////
Param::Param(Param *_newParam)
  : key(""), required(false), set(false), typeName("")
{
  /*if (params == NULL)
    gzthrow("Param vector is NULL\n");
    */
  if (params)
    params->push_back(_newParam);
}

//////////////////////////////////////////////////
Param::~Param()
{
}

//////////////////////////////////////////////////
std::string Param::GetTypeName() const
{
  return this->typeName;
}

//////////////////////////////////////////////////
bool Param::IsBool() const
{
  return this->GetTypeName() == "bool";
}

//////////////////////////////////////////////////
bool Param::IsInt() const
{
  return this->GetTypeName() == "int";
}

//////////////////////////////////////////////////
bool Param::IsUInt() const
{
  return this->GetTypeName() == "unsigned int";
}

//////////////////////////////////////////////////
bool Param::IsFloat() const
{
  return this->GetTypeName() == "float";
}

//////////////////////////////////////////////////
bool Param::IsDouble() const
{
  return this->GetTypeName() == "double";
}

//////////////////////////////////////////////////
bool Param::IsChar() const
{
  return this->GetTypeName() == "char";
}

//////////////////////////////////////////////////
bool Param::IsStr() const
{
  return this->GetTypeName() == "string";
}

//////////////////////////////////////////////////
bool Param::IsVector3() const
{
  return this->GetTypeName() == "vector3";
}

//////////////////////////////////////////////////
bool Param::IsVector2i() const
{
  return this->GetTypeName() == "vector2i";
}

//////////////////////////////////////////////////
bool Param::IsVector2d() const
{
  return this->GetTypeName() == "vector2d";
}

//////////////////////////////////////////////////
bool Param::IsQuaternion() const
{
  return this->GetTypeName() == "quaternion";
}

//////////////////////////////////////////////////
bool Param::IsPose() const
{
  return this->GetTypeName() == "pose";
}

//////////////////////////////////////////////////
bool Param::IsColor() const
{
  return this->GetTypeName() == "color";
}

//////////////////////////////////////////////////
bool Param::IsTime() const
{
  return this->GetTypeName() == "time";
}

//////////////////////////////////////////////////
bool Param::Set(const bool &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const int &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const unsigned int &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const float &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const double &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const char &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const std::string &_value)
{
  return this->SetFromString(_value);
}

/////////////////////////////////////////////////
bool Param::Set(const char *_value)
{
  return this->SetFromString(std::string(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Vector3 &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Vector2i &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Vector2d &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Quaternion &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Pose &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Color &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Set(const Time &_value)
{
  return this->SetFromString(boost::lexical_cast<std::string>(_value));
}

//////////////////////////////////////////////////
bool Param::Get(bool &_value)
{
  if (this->IsBool())
  {
    _value = ((ParamT<bool>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a bool\n";
    return false;
  }
}

//////////////////////////////////////////////////
bool Param::Get(double &_value)
{
  if (this->IsDouble())
  {
    _value = ((ParamT<double>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is a ["
          << this->typeName << "], attempting to get as a double.\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(float &_value)
{
  if (this->IsFloat())
  {
    _value = ((ParamT<float>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a float\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(Color &_value)
{
  if (this->IsColor())
  {
    _value = ((ParamT<Color>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a color\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(Time &_value)
{
  if (this->IsTime())
  {
    _value = ((ParamT<Time>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a time\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(Pose &_value)
{
  if (this->IsPose())
  {
    _value = ((ParamT<Pose>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a pose\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(Vector3 &_value)
{
  if (this->IsVector3())
  {
    _value = ((ParamT<Vector3>*)this)->GetValue();
    return true;
  }
  else
  {
    // sdfwarn << "Parameter [" << this->key
    //        << "] is not a vector3, parse as string\n";
    std::string val_str = this->GetAsString();
    std::vector<double> elements;
    std::vector<std::string> pieces;
    boost::split(pieces, val_str, boost::is_any_of(" "));
    if (pieces.size() != 3)
    {
      sdferr <<
        "string does not have 3 pieces to parse into Vector3, using 0s\n";
      return false;
    }
    else
    {
      for (unsigned int i = 0; i < pieces.size(); ++i)
      {
        if (pieces[i] != "")
        {
          try
          {
            elements.push_back(boost::lexical_cast<double>(pieces[i].c_str()));
          }
          catch(boost::bad_lexical_cast &e)
          {
            sdferr << "value ["
                  << pieces[i]
                  << "] is not a valid double for Vector3[" << i << "]\n";
            return false;
          }
        }
      }
      _value.x = elements[0];
      _value.y = elements[1];
      _value.z = elements[2];
      return true;
    }
  }
}

/////////////////////////////////////////////////
bool Param::Get(Vector2i &_value)
{
  if (this->IsVector2i())
  {
    _value = ((ParamT<Vector2i>*)this)->GetValue();
    return true;
  }
  else
  {
    // sdfwarn << "Parameter [" << this->key
    //        << "] is not a vector2i,parse as string\n";
    std::string val_str = this->GetAsString();
    std::vector<int> elements;
    std::vector<std::string> pieces;
    boost::split(pieces, val_str, boost::is_any_of(" "));
    if (pieces.size() != 2)
    {
      sdferr <<
        "string does not have 2 parts to parse into Vector2i, using 0s\n";
      return false;
    }
    else
    {
      for (unsigned int i = 0; i < pieces.size(); ++i)
      {
        if (pieces[i] != "")
        {
          try
          {
            elements.push_back(boost::lexical_cast<int>(pieces[i].c_str()));
          }
          catch(boost::bad_lexical_cast &e)
          {
            sdferr << "value ["
                  << pieces[i]
                  << "] is not a valid double for Vector2i[" << i << "]\n";
            return false;
          }
        }
      }
      _value.x = elements[0];
      _value.y = elements[1];
      return true;
    }
  }
}

/////////////////////////////////////////////////
bool Param::Get(Vector2d &_value)
{
  if (this->IsVector2d())
  {
    _value = ((ParamT<Vector2d>*)this)->GetValue();
    return true;
  }
  else
  {
    // sdfwarn << "Parameter [" << this->key
    //        << "] is not vector2d, parse as string\n";
    std::string val_str = this->GetAsString();
    std::vector<double> elements;
    std::vector<std::string> pieces;
    boost::split(pieces, val_str, boost::is_any_of(" "));
    if (pieces.size() != 2)
    {
      sdferr <<
        "string does not have 2 pieces to parse into Vector2d, using 0s\n";
      return false;
    }
    else
    {
      for (unsigned int i = 0; i < pieces.size(); ++i)
      {
        if (pieces[i] != "")
        {
          try
          {
            elements.push_back(boost::lexical_cast<double>(pieces[i].c_str()));
          }
          catch(boost::bad_lexical_cast &e)
          {
            sdferr << "value ["
                  << pieces[i]
                  << "] is not a valid double for Vector2d[" << i << "]\n";
            return false;
          }
        }
      }
      _value.x = elements[0];
      _value.y = elements[1];
      return true;
    }
  }
}

/////////////////////////////////////////////////
bool Param::Get(int &_value)
{
  if (this->IsInt())
  {
    _value = ((ParamT<int>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not an int\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(unsigned int &_value)
{
  if (this->IsUInt())
  {
    _value = ((ParamT<unsigned int>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not an unsigned int\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(char &_value)
{
  if (this->IsChar())
  {
    _value = ((ParamT<char>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not an unsigned int\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(std::string &_value)
{
  if (this->IsStr())
  {
    _value = ((ParamT<std::string>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a string\n";
    return false;
  }
}

/////////////////////////////////////////////////
bool Param::Get(Quaternion &_value)
{
  if (this->IsQuaternion())
  {
    _value = ((ParamT<Quaternion>*)this)->GetValue();
    return true;
  }
  else
  {
    sdferr << "Parameter [" << this->key << "] is not a quaternion\n";
    return false;
  }
}

/////////////////////////////////////////////////
void Param::SetDescription(const std::string &_desc)
{
  this->description = _desc;
}

/////////////////////////////////////////////////
std::string Param::GetDescription() const
{
  return this->description;
}
