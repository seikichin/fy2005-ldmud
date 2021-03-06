#include <mxp.h>
#include <telnet.h>

private nosave mapping mxp_version_info;
private nosave mapping mxp_support_info;

public mixed QueryMXP();

public void init_mxp() {

 if (!interactive() || !QueryMXP())
        return;
  mxp_version_info = ([]);
  mxp_support_info = ([ MXP_SUPPORT_ENABLED: ({}), MXP_SUPPORT_DISABLED: ({}) ]);
  // Tell the client that from now on we are sending MXP sequences
  binary_message(({IAC, SB, TELOPT_MXP, IAC, SE}));

  // Switch to "permanent secure" mode, MXP tags now enabled
  efun::write(process_mxp(MXPMODE(6), QueryMXP()));
//  efun::write(process_mxp(MXPTAG("VERSION"), QueryMXP()));
//  efun::write(process_mxp(MXPTAG("SUPPORT"), QueryMXP()));
//  efun::write(process_mxp(MXPMODE(6) + MXPTAG("VERSION") + "\n", QueryMXP()));
//  efun::write(process_mxp(MXPMODE(6) + MXPTAG("SUPPORT") + "\n", QueryMXP()));
  efun::write(process_mxp(MXPTAG("!-- Set up MXP elements --"), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RNum FLAG=\"RoomNum\" ATT=\"id\" EMPTY"), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RName FLAG=\"RoomName\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RDesc FLAG=\"RoomDesc\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT RExits FLAG=\"RoomExit\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT Prompt FLAG=\"Prompt\""), QueryMXP()));
  efun::write(process_mxp(MXPTAG("!ELEMENT Ex \"<send>\""), QueryMXP()));
}

public void SetMXPVersion(mapping m = ([])) {
  if (!mxp_version_info)
    mxp_version_info = ([]);
  mxp_version_info = m;
}

public void SetEnabledMXPSupportInfo(string *s = ({})) {
  if (!mxp_support_info)
    mxp_support_info = ([]);
  mxp_support_info[MXP_SUPPORT_ENABLED] = s;
}

public void SetDisabledMXPSupportInfo(string *s = ({})) {
  if (!mxp_support_info)
    mxp_support_info = ([]);
  mxp_support_info[MXP_SUPPORT_DISABLED] = s;
}

public mapping QueryMXPVersion() {
  return mxp_version_info || ([]);
}

public mapping QueryMXPSupportInfo() {
  return mxp_support_info || ([ MXP_SUPPORT_ENABLED: ({}), MXP_SUPPORT_DISABLED: ({}) ]);
}

