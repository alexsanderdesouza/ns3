/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2015 UFRGS
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Alexsander de Souza <asouza@inf.ufrgs.br>
 */

#include "bfd-echo-helper.h"

namespace ns3 {
BfdEchoHelper::BfdEchoHelper(void)
{
  m_factory.SetTypeId(BfdEchoAgent::GetTypeId());
}

void BfdEchoHelper::SetAttribute(std::string name, const AttributeValue &value)
{
  m_factory.Set(name, value);
}

ApplicationContainer BfdEchoHelper::Install(Ptr<Node> node) const
{
  return ApplicationContainer(InstallPriv(node));
}

Ptr<Application> BfdEchoHelper::InstallPriv(Ptr<Node> node) const
{
  Ptr<Application> app = m_factory.Create<BfdEchoAgent>();
  node->AddApplication(app);

  return app;
}
}
