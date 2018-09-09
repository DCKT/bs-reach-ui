type callbackEvent = unit => unit;

[@bs.deriving abstract]
type commonjsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
};

module Menu = {
  [@bs.module "@reach/menu-button"]
  external reactClass : ReasonReact.reactClass = "Menu";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};

module MenuButton = {
  [@bs.module "@reach/menu-button"]
  external reactClass : ReasonReact.reactClass = "MenuButton";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};

module MenuList = {
  [@bs.module "@reach/menu-button"]
  external reactClass : ReasonReact.reactClass = "MenuList";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};

[@bs.deriving abstract]
type menuItemJsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
  onClick: Js.Nullable.t(callbackEvent),
  onSelect: callbackEvent,
  onKeyDown: Js.Nullable.t(callbackEvent),
  onMouseMove: Js.Nullable.t(callbackEvent),
};

module MenuItem = {
  [@bs.module "@reach/menu-button"]
  external reactClass : ReasonReact.reactClass = "MenuItem";
  let make =
      (
        ~onSelect,
        ~className=?,
        ~style=?,
        ~onKeyDown=?,
        ~onMouseMove=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        menuItemJsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
          ~onMouseMove=Js.Nullable.fromOption(onMouseMove),
          ~onKeyDown=Js.Nullable.fromOption(onKeyDown),
          ~onSelect,
        ),
      children,
    );
};

[@bs.deriving abstract]
type menuLinkJsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
  component: Js.Nullable.t(string),
  [@bs.as "to"]
  to_: Js.Nullable.t(string),
  onClick: Js.Nullable.t(unit => unit),
  href: Js.Nullable.t(string),
};

module MenuLink = {
  [@bs.module "@reach/menu-button"]
  external reactClass : ReasonReact.reactClass = "MenuLink";
  let make =
      (
        ~to_=?,
        ~className=?,
        ~style=?,
        ~onClick=?,
        ~component=?,
        ~href=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        menuLinkJsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
          ~onClick=Js.Nullable.fromOption(onClick),
          ~component=Js.Nullable.fromOption(component),
          ~href=Js.Nullable.fromOption(href),
          ~to_=Js.Nullable.fromOption(to_),
        ),
      children,
    );
};