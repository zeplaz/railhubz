
#pragma once

#include "system_org.hpp"
#include "Cmd_agent_v3Operaor.hpp"

namespace driver
{
    static Cmd_agent_operator m_cmd_agent_op;
    void initializer();
    void drive_loop();
}
